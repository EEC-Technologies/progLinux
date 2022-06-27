#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

/******************************************************************************/
/*
 * Fonctions externes
*/
/******************************************************************************/
extern void attente_aleatoire();
extern int place_aleatoire();
extern int * attacher_segment_memoire();
extern int P();
extern int V();
extern int i;

/******************************************************************************/
/*
 * Fonctions 
*/
/******************************************************************************/

bool entree_voiture(int *mem, int semid, int nb_place_vendu, int num_caisse) {                                       
bool place_attribuee=false;

/* On protège l'accès à la shm */
P(semid);

/* Reste-t-il des places libres ? */
  if(*mem != 0){
    if(*mem - nb_place_vendu < 0) {
      //printf("La caisse vend %d place\n", nb_place_vendu);
      printf("Caisse %d : pas assez de places disponibles\n", num_caisse);
      place_attribuee=true;
    } else {
      if(nb_place_vendu == 0){
        place_attribuee=true;
      } 
      else {
        *mem=(*mem - nb_place_vendu);
        place_attribuee=true;
        printf("La caisse numero %d vend %d \n", num_caisse, nb_place_vendu);
      }    
    }
  }

  /* On écrit dans la shm */
  

/* On protège l'accès à la shm */
  V(semid);

  return (place_attribuee);
}


/******************************************************************************/
/*
 * Programme principal
*/
/******************************************************************************/
int main(int argc, char *argv[]) {

unsigned int delais=3;
int max_places = 7;

int shmid=atoi(argv[1]);
int semid=atoi(argv[2]);
int num_caisse=atoi(argv[4]);

int *mem;

/*
printf("Je suis %s, shmid=%d, semid=%d\n", argv[0], shmid, semid);
*/

/* Attachement du segment de mémoire partagée */
mem=attacher_segment_memoire(mem, &shmid);


srand(time(NULL));
    
while (1) {

  struct timeval interval;
  struct timeval places;
  gettimeofday(&interval, NULL);
  gettimeofday(&places, NULL);
  attente_aleatoire(&interval,delais);

  int nb_place_vendu = place_aleatoire(&places,max_places);
  
  if (entree_voiture(mem, semid, nb_place_vendu, num_caisse) == false) {
    break;  
  }
}

return(0);
}
