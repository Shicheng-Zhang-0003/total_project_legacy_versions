#include <stdio.h>
#include <stdlib.h>

int ABS(int number) {
    return number < 0 ? -number : number;
}

void main_algorithm() {
    int ystart = 0, yend = 0, xstart = 0, xend = 0;
    float a, b, c;

    printf("Enter the coefficients a, b, and c of the quadratic equation y = ax^2 + bx + c:\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    do {
        printf("Enter where the x axis is going to start (must be less or equal to 0): ");
        scanf("%d", &xstart);
    } while (xstart > 0);

    do {
        printf("Enter where the x axis is going to end (must be greater or equal to 0): ");
        scanf("%d", &xend);
    } while (xend < 0);

    do {
        printf("Enter where the y axis is going to start (must be less or equal to 0): ");
        scanf("%d", &ystart);
    } while (ystart > 0);

    do {
        printf("Enter where the y axis is going to end (must be greater or equal to 0): ");
        scanf("%d", &yend);
    } while (yend < 0);

    int tozerospacey = 0 - ystart;
    int tozerospacex = 0 - xstart;
    int xtotal = ABS(xstart) + xend + 1;
    int ytotal = ABS(ystart) + yend + 1;

    int **grid = malloc(ytotal * sizeof(int *));
    for (int i = 0; i < ytotal; ++i) {
        grid[i] = malloc(xtotal * sizeof(int));
    }

    for (int xx = 0; xx < xtotal; ++xx) {
        for (int yy = 0; yy < ytotal; ++yy) {
            grid[yy][xx] = 0;
        }
    }

    printf("\nTable of (x, y) values:\n");
    printf(" x \t y \n");
    for (int x = xstart; x <= xend; ++x) {
        float y = a * x * x + b * x + c;
        if (y >= ystart && y <= yend) {
            printf("%d\t%.2f\n", x, y);
            int translated_x = x + tozerospacex;
            int translated_y = ytotal - 1 - ((int)y + tozerospacey);
            if (translated_x >= 0 && translated_x < xtotal && translated_y >= 0 && translated_y < ytotal) {
                grid[translated_y][translated_x] = 1;
            }
        }
    }

    for (int y = 0; y < ytotal; ++y) {
        for (int x = 0; x < xtotal; ++x) {
            if ((y == ytotal - 1 - tozerospacey) && (x == tozerospacex)) {
                printf(grid[y][x] == 0 ? "O" : "$");
            } else if (y == ytotal - 1 - tozerospacey) {
                printf(grid[y][x] == 0 ? "-" : "$");
            } else if (x == tozerospacex) {
                printf(grid[y][x] == 0 ? "|" : "$");
            } else {
                printf(grid[y][x] == 0 ? " " : "$");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < ytotal; ++i) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    main_algorithm();
    return 0;
}
