# Project: cinema

OBJ  = sem_op.o shm_op.o aleatoire.o
LINKOBJ  = $(OBJ)
BIN  = parking entree sortie
CFLAGS = -g #-Wall

all: cinema entree sortie affichage

cinema: $(LINKOBJ) shm_const.h cinema.c
	$(CC) cinema.c $(LINKOBJ) -o cinema $(CFLAGS)

sortie: $(LINKOBJ) shm_const.h sortie.c
	$(CC) sortie.c $(LINKOBJ) -o sortie $(CFLAGS)

entree: $(LINKOBJ) shm_const.h entree.c
	$(CC) entree.c $(LINKOBJ) -o entree $(CFLAGS)
	
affichage: $(LINKOBJ) shm_const.h affichage.c
	$(CC) affichage.c $(LINKOBJ) -o affichage $(CFLAGS) -lpthread

shm_op.o: shm_op.c shm_const.h
	$(CC) -c shm_op.c $(CFLAGS)

sem_op.o: sem_op.c shm_const.h
	$(CC) -c sem_op.c $(CFLAGS)

aleatoire.o: aleatoire.c
	$(CC) -c aleatoire.c $(CFLAGS)
	
affichage.o: affichage.c
	$(CC) -c affichage.c $(CFLAGS)
	


clean: 
	rm -f $(OBJ) $(BIN)


