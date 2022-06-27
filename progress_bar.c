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


void progress_bar(int *mem, int nb_place) {    


    printf("\t\t\t\t\t\tTAUX DE PLACE VENDU EN %\n");
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

    //affichage_places(mem,semid,film);
    char term_cmd[128];
    progress_bar(mem, nb_place);


    return(0);
}
