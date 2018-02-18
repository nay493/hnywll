#include<stdio.h>
#include<string.h>

void main(int argc,char *argv[])
{ char buffer[100];

  if(argc => 2)
  {
  if(strstr(argv[1], "jpg"))
    sprintf(buffer,"jpegoptim %s",argv[1]);
  else if(strstr(argv[1], "png"))
    sprintf(buffer,"optipng %s",argv[1]);
  }
  else
    printf("./a.out <image|file|audio|video>\n");
  system(buffer);
}
