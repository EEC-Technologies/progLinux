
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "shm_const.h"

extern int creer_initialiser_semaphore();
extern int * attacher_segment_memoire();
extern int P();
extern int V();

extern int creer_segment_memoire();

int main(int argc, char *argv[])
{
    

    int nombre_caisses;
    char * nombre_caisses_str;
    int nb_proc;
    char * titre_film;
    int nombre_places_cinema; /* Pour écriture dans la shm */
    char * nombre_places_cinema_str; /* Pour conversion du semid (int) en chaine */

    int shmid; /* Id du segment de mémoire partagé */
    int semid; /* Id du sémaphore */

    char shmid_str[20]; /* Pour conversion du shmid (int) en chaine */
    char semid_str[20]; /* Pour conversion du semid (int) en chaine */

    int * mem; /* Adresse du segment de mémoire partagée */

    char param_gnome_terminal[80];

    if ( argc != 4 ) {
        fprintf(stderr, "Usage : %s nombre_places_cinema / nombre de caisses : titre du film\n", argv[0]);
        return(3);
    }

    nombre_places_cinema_str=argv[1];
    nombre_places_cinema=atoi(nombre_places_cinema_str);
    
    nombre_caisses_str=argv[2];
    nombre_caisses=atoi(nombre_caisses_str);
    
    titre_film=argv[3];
    


 /* Avant de créer les fils :
    * - on crée le semaphore
    * - on crée le segment de mémoire partagé
    * - on s'attache le segment de mémoire partagé
    * - on initialise le noombre de places de parking libres dans la shm
    */

    /* Création sémaphore */
    creer_initialiser_semaphore(CLE_SEM, &semid);

    /* Création segment de mémoire partagé */
    creer_segment_memoire(CLE_SHM, &shmid);


    /* Attachement du segment de mémoire partagée */
    mem=attacher_segment_memoire(mem, &shmid);

    /* Pas besoin de sémaphore on est seul :-) */
    *mem=nombre_places_cinema;

    /* Conversion des shmid et semid  (int) en chaine pour appel programme externe */
    sprintf(shmid_str, "%d", shmid);
    sprintf(semid_str, "%d", semid);

    int pid_caisse[nombre_caisses+1];
    char num_caisse_str[5];
    nb_proc=nombre_caisses+1;
  
  
  for(int i = 0 ;  i<nombre_caisses ; i++){
  	
  	pid_caisse[i] = fork();
  	if ( pid_caisse[i] == 0 ){
  		sprintf(num_caisse_str, "%d", i);
  		execl("entree", "entree", shmid_str, semid_str, nombre_places_cinema_str, num_caisse_str, NULL);
  		exit(0);
  	}
		
  }
  
  int status;
  
  
  pid_caisse[nb_proc] = fork();
  if ( pid_caisse[nb_proc] == 0 ){
  		execl("affichage", "affichage", shmid_str, semid_str, nombre_places_cinema_str, titre_film,NULL);
  	}
  	
  	if (pid_caisse[nb_proc] > 0) {
  		for(int i = 0 ;  i<=nb_proc ; i++){
  			waitpid(pid_caisse[i], &status,0);
  		}
  		system("ipcrm -m `ipcs -a | grep 0x00000555 | awk '{print $2}'` -s `ipcs -a | grep 0x00000111 | awk '{print $2}'`");
  	}
}
