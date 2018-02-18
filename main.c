#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include <stdlib.h> // exit()
#define MAX 100

// To vaoid warning return type is void * ; It is better to pass void * and
// inside the thread typecast it to proper data-type.
void *threadfunc(void *argv)
{
printf("In thread\n");
printf("*argv=%s\n",(char *)argv);
char buffer[MAX];

 if(strstr((char *)argv, "jpg")) // If arg matches jpg; then go for jpg encoding or jpg compression.
   sprintf(buffer,"jpegoptim %s",(char *)argv);
 else if(strstr((char *)argv, "png"))
   sprintf(buffer,"optipng %s",(char *)argv);
 else if(strstr((char *)argv, "txt"))
   sprintf(buffer,"tar -cvzf data_files/data.tar.gz %s",(char *)argv);
 else
   sprintf(buffer,"tar -cvzf data_files/def_data.tar.gz %s",(char *)argv);
//https://www.cyberciti.biz/howto/question/general/compress-file-unix-linux-cheat-sheet.php

  system(buffer);
  return 0;
}


int main(int argc,char *argv[])
{
  pthread_t tid;
  int i;
  if(argc <= 2)
  {
    printf("./a.out <image|file|audio|video>\n");
    exit(255);
   }
  for(i=0;i<argc;i++)
    pthread_create(&tid, NULL, threadfunc, argv[i]);
  pthread_exit(NULL);
  return 0;
}
