#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>                   // used to
#include <sys/socket.h>                  //  create socket

#include <netinet/in.h>                  //to store addresses information
#include <string.h>

int create_socket();
int binding(int);
int communication(int);
int chat(int);

int main()
{
int client_socket;
client_socket = create_socket();
}


// creating socket
int create_socket()
{
  int  client_socket;
  client_socket =  socket(AF_INET, SOCK_STREAM, 0);
  if(client_socket == -1)
  {
    perror("Ploblem in connecting socket:  \n");
    exit(0);
  }
  else
  {
     printf("Socket created\n");
     binding(client_socket);
     return 0;
  }
}


// Bind()
int binding(int client_socket)
{

  //printf("%s",client_socket);
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(90);        //make sure  BIG Endia format  folws
  server_address.sin_addr.s_addr =INADDR_ANY;  //It will conenct on all avilable interfaceit will connect to local machine

  if(connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
   {
    perror("ERROR connecting");
    exit(0);
   }
  else
  {
    perror("Connection Created ....");
    communication(client_socket);
    return 0;
  }

}

//recv and  send
int communication(int client_socket)
{

  char server_response[255],output;
  output = recv(client_socket, &server_response, sizeof(server_response),0);
  printf("%s", &server_response);
  chat(client_socket);
  close(client_socket);
  return 0;
}


int chat(int client_socket)
{
while(1)
{
  char * buffer=(char*)(malloc(sizeof(char)*1024));
  int buffsize=1024,i=0;
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
    printf("client program ended\n");
    return 0;
}
}
