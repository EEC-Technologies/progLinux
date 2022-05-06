#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>






int main(int argc, char *argv[])
{
  int pid_caisse[16];
  int i;
  
  
  for(i = 0 ;  i<15 ; i++){
  	
  	pid_caisse[i] = fork();
  	if ( pid_caisse[i] == 0 ){
  		printf("processus caisse\n");
  		sleep(100);
  		exit(0);
  	}
		
  }
  
  int status;
  
  
  pid_caisse[16] = fork();
  if ( pid_caisse[16] == 0 ){
  		printf("processus affichage\n");
  		while(true){
  			int a=0;
  		}
  	}
  	
  	if (pid_caisse[16] > 0) {
  		for(i = 0 ;  i<16 ; i++){
  			waitpid(pid_caisse[i], &status,0);
  		}
  	}
  
  
   
}
