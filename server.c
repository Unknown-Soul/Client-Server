#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include <string.h>


int create_socket();
int binding(int);
int communication(int);
int chat(int);

int main()
{
 int server_socket, bind,  communicate;
 create_socket();
}


int create_socket()
{
 int network_socket = socket(AF_INET, SOCK_STREAM, 0);
 if(network_socket == -1)
  {
   perror("Their is an error");
   exit(0);
  }
 else
  {
   printf("Socket Created......\n");
   binding(network_socket);
   return 0;
  }
}


// Bind()
int binding(int network_socket)
{
 // int _socket = network_socket;
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(90);        //make sure  BIG Endia format  folws
  server_address.sin_addr.s_addr =INADDR_ANY;  //It will conenct on all avilable interfaceit will connect to local machine

  if(bind(network_socket, (struct sockaddr* ) &server_address, sizeof(server_address)) < 0)
  {
  perror("ERROR connecting");
  exit(0);
  }
 else
  {
    printf("Connection Created ....\n");
    if(listen(network_socket, 10) == 0)
      {
       // printf("Listening...");
        communication(network_socket);
        return 0;
      }
    else
      {
        perror("Faild To Listen....");
        return -1;
      }
   }
}


int communication(int network_socket)
{
  char server_message[256] = "All Good You Can Start Chatting.......\n";

  int  client_socket  =  accept(network_socket,NULL,NULL);   //accept waiting request
  send(client_socket, server_message, sizeof(server_message),0);
  chat(client_socket);
  close(network_socket);
  return 0;
}




int chat(int client_socket)

{
  char * buffer=(char*)(malloc(sizeof(char)*1024));
  int buffsize=1024;
  int l=0;char c;char msg[200];
 while(1)
 {
      recv(client_socket,buffer,buffsize,0);
      l=0;
      if(strncmp(buffer, "bye", 3) == 0)
      {
          close(client_socket);
          break;
      }
      fprintf(stdout, "Client : %s", buffer);
      printf("\n");
      printf("server: ");
      l=0;
      while((c=getchar())!='\n')
        {
          msg[l++]=c;
        }
       msg[l]='\0'; l++;
      send(client_socket,msg,l,0);

 }
printf("server program ended\n");
return 0;
}
