#include <ncurses.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>



int main(void) {
    WINDOW *boite;
    char *msg= "Texte au centre";
    int taille= strlen(msg);
    
    initscr();
    while(1) {
        clear();    // Efface la fenêtre (donc l'ancien message)
        mvprintw(LINES/2, (COLS / 2) - (taille / 2), msg);
        refresh();
        if(getch() != 410)
            break;
    }
    
    endwin();
    
    free(boite);
    
    return 0;
}