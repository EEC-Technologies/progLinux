#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

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

void affichage(int *mem, int semid, int nb_place_vendu) {                                       

while(1){
    printf("\rLa caisse numero 0 vend %d", *mem);
    fflush(stdout);
    sleep(5);
    if( *mem == 0 ){
        break;
    }   
}
printf("\n");
}

void progress_bar(int *mem, int semid, int nb_place) {                                       

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
printf("\t\t\t\t");
for (int i = 0; i < 100; i++) {
    int valeur = ( 100 - (( *mem * 100) / nb_place ));
    i = valeur;
    if(( i == 0) || (i == 100)){
        printf("%c", a);
        fflush(stdout);
    }
    else{
        for (int u = 1; u < u ; u++){
            printf("%c", b);
            fflush(stdout);
        }
    }
    sleep(1);
    }
//system("tput sgr0");
printf("\n\n");
return 0;    
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
int nb_place=atoi(argv[3])

int *mem;

/*
printf("Je suis %s, shmid=%d, semid=%d\n", argv[0], shmid, semid);
*/

/* Attachement du segment de mémoire partagée */
mem=attacher_segment_memoire(mem, &shmid);

affichage(mem, semid, nb_place_vendu);
progress_bar(mem, semid, nb_place_vendu);


return(0);
}
