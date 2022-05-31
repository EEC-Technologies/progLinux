#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define ATTENTE_MAX 3

void attente_aleatoire(struct timeval *interval, unsigned int delais) {

/* Initialisation du dÃ©sordre */

    sleep(interval->tv_usec % delais);

}

int place_aleatoire(struct timeval *interval, int max){

    return (interval->tv_usec % max);
}

