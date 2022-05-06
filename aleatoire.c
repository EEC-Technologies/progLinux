#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ATTENTE_MAX 3

void attente_aleatoire(unsigned int delais) {

/* Initialisation du dÃ©sordre */


/* Attente */
sleep((unsigned int)(rand() % ATTENTE_MAX));

}

