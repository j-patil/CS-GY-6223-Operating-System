//This code is made by studying wc.c program
#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
head(int fd, int number, char *name)
{
int i, n, j;
int initial =0,count =0;
  
  while((n = read(fd, buf, sizeof(buf))) > 0){


    for(i=0; i<n; i++){
    	if(buf[i] == '\n'){
		for(j=initial; j<i && count < number; j++) //The code prints required lines.
		printf(1, "%c",buf[j]);
		initial = i; 
		count++;
 	}       
     }
  }
  
    if(n < 0){
    printf(1, "head: read error\n");
    exit();}

  printf(1, "\n");//command on new line
  exit();
}

int
main(int argc, char *argv[])
{
  int fd, temp;
  if(argc <= 1){ //The following code is for standard input (i.e grep command)
    head(0, 10, ""); 
    exit();
  }

	if(argv[1][0]=='-'){ //The following code will execute 'head -number' command
	if((fd = open(argv[2], 0)) < 0){
	printf(1, "head: cannot open %s\n", argv[2]);
	exit(); }
	temp=atoi(argv[1]+1);
	head(fd, temp, argv[2]);
	close(fd);
	}

	else if(argc==2){ //The following code will execute 'head README' command
	if((fd = open(argv[1], 0)) < 0){
	printf(1, "head: cannot open %s\n", argv[1]);
	exit();}
	head(fd, 10, argv[1]);
	close(fd);
	}

  exit();
}
