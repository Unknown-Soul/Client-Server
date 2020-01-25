#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc,char* argv[])
{
  int number,i =0,check;
  char name[20], email[30],path[40];

  size_t bufsize=50;
  if(argc < 2)
    {
      printf("please eneter IP and Portno");
      exit(1);
    }

 printf("WELCOME\n");
 printf("DO YOU WANT TO CREATE SSH KEY OR DO YOU ALREADY HAVE IT??\n");
 printf("1: WANT TO CREATE\n2: ALREADY HAVE IT\n");
 printf("Please Enter Your Choice(1/2)\n");
 scanf("%d",&number);
 printf("Enter Your Name\n");
 scanf("%s",&name);
 printf("Enter Your Email\n");
 scanf("%s",&email);
 switch (number)
 {
   case 1: system("ssh-keygen");
           break;
   case 2: printf("Enter file path of the key\n");
           scanf("%s",&path);
           break;
   default:printf("Something Went Wrong!!!!!!!\n");
            break;
 }
char cmdd[30],cmd[30];

//
sprintf(cmdd,"ssh-copy-id chat@%s", argv[1]);
sprintf(cmd,"ssh chat@%s", argv[1]);// command to copy key in the server
//printf("%s",cmdd)
if(system(cmdd) == 0)
  {

    if(system(cmd)!=0)
    {
        printf("error");
    }
  }
return 0;
}
