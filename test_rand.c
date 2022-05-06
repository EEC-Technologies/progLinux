#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
#define SIZE 100
#define NUMS_TO_GENERATE 10

int main() {
    srand(time(NULL));
    while(1){
    	int test = rand() % 7;
        printf("%d\n", test);
    }

    exit(EXIT_SUCCESS);
}
