#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

/******************************************************************************/
/*
 * Fonctions externes
*/
/******************************************************************************/
extern void attente_aleatoire();
extern int * attacher_segment_memoire();
extern int P();
extern int V();
extern int i;

/******************************************************************************/
/*
 * Fonctions 
*/
/******************************************************************************/


void* print_once(void* pString)
{

    sleep(5);	
    //int* m = &pString;
    int *myid = (int *) pString;
    printf("%d", (int *) pString);

    return NULL;
}

void affichage(int *mem) {                                       

while(1){
    printf("\rIl reste %d place(s) de disponible", *mem);
    fflush(stdout);
    sleep(1);
    if( *mem == 0 ){
        break;
    }   
}
printf("\n");
}

void *affichage1(void *p) {       
                 
int *mem = (int *) p;        


while(1){
    printf("\rIl reste %d place(s) de disponible", *mem);
    fflush(stdout);
    sleep(1);
    if( *mem == 0 ){
        break;
    }   
}
printf("\n");
}

void progress_bar(int *mem, int nb_place) {    


printf("\t\t\t\t\t\tBARRE DE PROGRESSION EN %\n");
char a = 124, b = 35, c=32;                                   
printf("\t");
for (int i = 0; i < 101; i++){
    if(( i == 0) || (i == 100)){
        printf("%c", a);
    }
    else{
        printf("%c", c);
    }
}


//system("echo -e '\e[1;32m'");

printf("\r");
printf("\t");
//printf("\t\t\t\t");
for (int i = 0; i < 100; i++) {
    int valeur = ( 100 - (( *mem * 100) / nb_place ));
    i = valeur;	
    if( i == 0){
        printf("%c", a);
        fflush(stdout);
        while(1){
        	if( *mem != nb_place ){
        		break;
        	}
        }
    }
    else{
    	printf("\r");
    	printf("\t");	
        for (int u = 0; u < i ; u++){
            if( u == 0){
            	printf("%c", a);
        	fflush(stdout);
            }
            else{
            	//printf("%d",i);
            	printf("%c", b);
            	fflush(stdout);
            	}
        }
    }
    sleep(1);
}
printf("\r");
printf("\t");
for (int u = 0; u < 100 ; u++){
            if(( u == 0) || (u == 100)){
            	printf("%c", a);
        	fflush(stdout);
            }
            else{
            	//printf("%d",i);
            	printf("%c", b);
            	fflush(stdout);
            	}
        }
//system("tput sgr0");
printf("\n\n");

}

void *progress_bar1(void *p) {    

int *mem = (int *) p;  
int nb_place=100;
char a = 124, b = 35, c=32;                                   

for (int i = 0; i < 101; i++){
    if(( i == 0) || (i == 100)){
        printf("%c", a);
    }
    else{
        printf("%c", c);
    }
}


//system("echo -e '\e[1;32m'");

printf("\r");
//printf("\t\t\t\t");
for (int i = 0; i < 100; i++) {
    int valeur = ( 100 - (( *mem * 100) / nb_place ));
    i = valeur;	
    if(( i == 0) || (i == 100)){
        printf("%c", a);
        fflush(stdout);
        while(1){
        	if( *mem != nb_place ){
        		break;
        	}
        }
    }
    else{
    	printf("\r");
    	int u;
    	if(u>i){
    		u=100;
    	}
        for (u = 0; u < i ; u++){
            if( u == 0){
            	printf("%c", a);
        	fflush(stdout);
            }
            else{
            	printf("%c", b);
            	fflush(stdout);
            	}
        }
    }
    sleep(1);
    }
//system("tput sgr0");
printf("\n\n");

return NULL;
   
}

/******************************************************************************/
/*
 * Programme principal
*/
/******************************************************************************/
int main(int argc, char *argv[]) {

unsigned int  delais=7;

int shmid=atoi(argv[1]);
int semid=atoi(argv[2]);
int nb_place=atoi(argv[3]);

int *mem;

/*
printf("Je suis %s, shmid=%d, semid=%d\n", argv[0], shmid, semid);
*/

/* Attachement du segment de mémoire partagée */
mem=attacher_segment_memoire(mem, &shmid);


pthread_t thread1;
pthread_t thread2;

long t;

//printf("salut : %d",*mem);



//sleep(3);
//progress_bar(mem, nb_place);

//pthread_create(&thread1, NULL, affichage1, mem);
//pthread_join(thread1, NULL);

//pthread_create(&thread2, NULL, progress_bar1, mem);
//pthread_join(thread2, NULL);


//pthread_create(&threads, NULL, affichage1,(int *)&mem);

affichage(mem);
//sleep(1);
//progress_bar(mem, nb_place);


return(0);
}
