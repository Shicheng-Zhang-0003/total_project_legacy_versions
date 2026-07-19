/*
 * This is a premature version of a slope-line determining program
 * for a multi-point linear equation cartesian graph in 2 dimensions.
 * It contains undertermined slope check as well as the ability to display 
 * decimal slope and y-intercept values. A version with fraction values and more
 * error checking for specific circumstances will be updated soon.
 *
 * Please reference this program should you use to code in your own programs.
 *
 * Copyright 2025. Shicheng Z. 14/04/25
 *
 * */
#include <stdio.h>
void main_algorithm () {
    int amt_points = 0;
    printf ("AMT POINTS:");
    scanf ("%d", &amt_points);
    float points [amt_points][2];
    for (int x = 0; x < amt_points; x++) {
        printf ("Point %d (x, y):", x);
        scanf ("%f %f", &points [x][0], &points [x][1]);
    } float slopes [amt_points - 1][2]; 
    int nan [amt_points - 1];
    for (int y = 0; y < amt_points - 1; y++) {
        float dx = points [y][0] - points [y + 1][0], dy = points [y][1] - points [y + 1][1];
        if (dx == 0) {
            if (dy == 0) {slopes [y][0] = 0, slopes [y][1] = 0, nan [y] = 0;}
            else {nan [y] = 1, slopes [y][1] = dy;}
        } else { 
            slopes [y][0] = dy / dx; //m
            slopes [y][1] = points [y + 1][1] - (slopes [y][0] * points [y + 1][0]); //b
            nan [y] = 0;
        } if (slopes [y][1] <= 0) {
            if (nan [y] == 0) {printf ("Eq line %d: y = %fx - %f\n", y, slopes [y][0], -slopes [y][1]);}
            else {printf ("Eq line %d: y = nanx - %f\n", y, slopes [y][1]);}
        } else {
            if (nan [y] == 0) {printf ("Eq line %d: y = %fx + %f\n", y, slopes [y][0], slopes [y][1]);}
            else {printf ("Eq line %d: y = nanx + %f\n", y, slopes [y][1]);} 
        }
    } 
} int main () {
    main_algorithm ();
    return 0;
}
