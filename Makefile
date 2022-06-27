# Project: cinema

OBJ  = sem_op.o shm_op.o aleatoire.o
LINKOBJ  = $(OBJ)
BIN  = parking entree
CFLAGS = -g #-Wall

all: cinema entree affichage progress_bar

cinema: $(LINKOBJ) shm_const.h cinema.c
	$(CC) cinema.c $(LINKOBJ) -o cinema $(CFLAGS)

entree: $(LINKOBJ) shm_const.h entree.c
	$(CC) entree.c $(LINKOBJ) -o entree $(CFLAGS)

affichage: $(LINKOBJ) shm_const.h affichage.c
	$(CC) affichage.c $(LINKOBJ) -o affichage $(CFLAGS) -lpthread
	
progress_bar: $(LINKOBJ) shm_const.h progress_bar.c
	$(CC) progress_bar.c $(LINKOBJ) -o progress_bar $(CFLAGS)

shm_op.o: shm_op.c shm_const.h
	$(CC) -c shm_op.c $(CFLAGS)

sem_op.o: sem_op.c shm_const.h
	$(CC) -c sem_op.c $(CFLAGS)

aleatoire.o: aleatoire.c
	$(CC) -c aleatoire.c $(CFLAGS)

affichage.o: affichage.c
	$(CC) -c affichage.c $(CFLAGS)

progress_bar.o: progress_bar.c
	$(CC) -c progress_bar.c $(CFLAGS)



clean:
	rm -f $(OBJ) $(BIN)
