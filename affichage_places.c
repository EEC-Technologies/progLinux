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
 * Variables Statiques 
*/
/******************************************************************************/

static int delais_affichage = 5;

/******************************************************************************/
/*
 * Fonctions 
*/
/******************************************************************************/

void affichage_places(int *mem, int semid, char* film) {

    

    while(1){

        P(semid);
        printf("\tIl reste %d place(s) de disponible pour le film %s\n", *mem,film);
        if( *mem == 0 ){
            V(semid);
            break;
        }   
        V(semid);
        sleep(delais_affichage);
        
    }

    

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
    char* film=argv[4];

    int *mem;

    /* Attachement du segment de mémoire partagée */
    mem=attacher_segment_memoire(mem, &shmid);

    affichage_places(mem,semid,film);
    return(0);
}
