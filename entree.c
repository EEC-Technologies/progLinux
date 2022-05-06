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

bool entree_voiture(int *mem, int semid, int nb_place_vendu) {                                       
bool place_attribuee=false;

/* On protège l'accès à la shm */
P(semid);

/* Reste-t-il des places libres ? */
if (*mem == 0) {
  /* No more */
  printf("Dans la shm il y a %d places\n", *mem);
}
else {
  /* On écrit dans la shm */
  if (*mem - nb_place_vendu < 0){
  	*mem=0;
  }
  else {
  	printf("La caisse vend %d place\n", nb_place_vendu);
  	*mem=(*mem - nb_place_vendu);
  	printf("Dans la shm il y a %d places\n", *mem);
  	place_attribuee=true;
  }
  
}

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

unsigned int  delais=7;

int shmid=atoi(argv[1]);
int semid=atoi(argv[2]);

int *mem;

/*
printf("Je suis %s, shmid=%d, semid=%d\n", argv[0], shmid, semid);
*/

/* Attachement du segment de mémoire partagée */
mem=attacher_segment_memoire(mem, &shmid);


srand(time(NULL));
    
while (1) {
  attente_aleatoire(delais);
	
  int nb_place_vendu = rand() % 7;
  if (entree_voiture(mem, semid, nb_place_vendu) == false) {
  	printf("fini\n");
    break;  
  }
}

return(0);
}
