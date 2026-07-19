/*
 * This is a recreation of the sliding game, where you can define the grid size.
 *
 * The aim of the game is to reposition all pieces into ascending order by row.
 * This program gives a baseline to the player for completing this task.
 *
 * It uses a vector reconstruction method to place pieces according to their specific 
 * spots.
 *
 * Please reference this program should you utilise it in your own code.
 *
 * Copyright 2025. Shicheng Z. 31/03/25
 * */
#include <stdio.h>
#include <stdlib.h>
int printout (int n, int grid [n][n]);
int printout (int n, int grid [n][n]) {
    for (int x2 = 0; x2 < n; x2++) {
        printf (" -  ");
    } printf ("\n");
    for (int y2 = 0; y2 < n; y2++) {
        for (int x3 = 0; x3 < n; x3++) {
            if (grid [y2][x3] != -1) {printf (" %d |", grid [y2][x3]);}
            else {printf ("   |");}
        } printf ("\n");  
        for (int x2 = 0; x2 < n; x2++) {
            printf (" -  ");
        } printf ("\n");
    } return 0;
} int checkbound (int n, int cx, int cy, int xc, int yc, int grid [n][n]);
int checkbound (int n, int cx, int cy, int xc, int yc, int grid [n][n]) {
    int nx = cx + xc, ny = cy + yc;
    if ((nx >= 0) && (nx < n)) {
        if ((ny >= 0) && (ny < n)) {
            if (grid [nx][ny] == -1) {;}
            else {return 0;}
        } else {return 0;}
    } else {return 0;} 
    return 1;
} void main_algorithm () {   
    int n = 0;
    printf ("Enter the size of the game grid:");
    scanf ("%d", &n);
    int grid [n][n];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf ("Enter the seed values:");
            scanf ("%d", &grid [x][y]);
        }
    } while (1) {
        system ("clear");
        int piece = 0;
        char cmd;
        printf ("Enter the piece that you want to move:");
        scanf ("%d", &piece);
        printf ("Enter the direction that you wish to move the piece in:");
        scanf (" %c", &cmd);
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < n; y1++) {
                if (grid [x1][y1] == piece) {
                    int possibility = 1, swp = 0;
                    if (cmd == 'a') {
                        possibility = checkbound (n, x1, y1, 0, -1, grid);
                        if (possibility == 1) {
                            swp = grid [x1][y1];
                            grid [x1][y1] = grid [x1][y1 - 1];
                            grid [x1][y1 - 1] = swp;
                        } else {printf ("Move not allowed.\n");}
                    } else if (cmd == 'w') {
                        possibility = checkbound (n, x1, y1, -1, 0, grid);
                        if (possibility == 1) {
                            swp = grid [x1][y1];
                            grid [x1][y1] = grid [x1 - 1][y1];
                            grid [x1 - 1][y1] = swp;
                        } else {printf ("Move not allowed.\n");}       
                    } else if (cmd == 'd') {
                        possibility = checkbound (n, x1, y1, 0, 1, grid);
                        if (possibility == 1) {
                            swp = grid [x1][y1];
                            grid [x1][y1] = grid [x1][y1 + 1];
                            grid [x1][y1 + 1] = swp;
                         } else {printf ("Move not allowed.\n");}
                    } else if (cmd == 's') {
                        possibility = checkbound (n, x1, y1, 1, 0, grid);
                        if (possibility == 1) {
                            swp = grid [x1][y1];
                            grid [x1][y1] = grid [x1 + 1][y1];
                            grid [x1 + 1][y1] = swp;
                        } else {printf ("Move not allowed.\n");}
                    } else if (cmd == 'q') {
                        printf ("Exiting.\n");
                        exit (0);
                    } else {
                        printf ("Option not in key bindings.\n");
                    }
                }
            }
        } printout (n, grid);
    }
} int main () {
    main_algorithm ();
    return 0;
}
