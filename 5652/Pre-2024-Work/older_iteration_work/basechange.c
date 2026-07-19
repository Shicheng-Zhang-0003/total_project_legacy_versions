/*
  This is a remake of the basechange program commenced previously earlier last year. It's purpose its to 
  convert any number of any base to another number of another base. Please note that letter recognition for 
  bases 11 and above have not been implemented yet as this is the prototype version of the program.

  Copyright 2024. Shicheng Z

  Named as basechange.c
  */
#include <stdio.h>
#include <math.h>
int size = 0, number = 0, base = 0, base2 = 0, total = 0;
int find_digits (int input);
int find_digits (int input) {
    int base10 = 10, exp = 1;
    while (1) {
        if ((input % base10) != input) {
            base10 = base10 * 10;
            ++exp;
        } else {
            break;
        }
    }
    return exp;
} void to_second_base (int number, int base);
void to_second_base (int number, int base) {
    int arr_size = 0;
    int temp_number = number;
    while (temp_number > 0) {
        temp_number /= base;
        ++arr_size;
    }
    int array2 [arr_size];
    for (int z = 0; z < arr_size; ++z) {
        array2 [z] = number % base;
        number = number / base;
    } for (int a = arr_size - 1; a >= 0; --a) {
        printf ("%d", array2 [a]);
    }
    printf ("\n");
} void main_algorithm () {
    printf ("Enter the base of said number: ");
    scanf ("%d", &base);
    printf ("Enter the base you wish to translate to: ");
    scanf ("%d", &base2);
    printf ("Enter the number you wish to translate: ");
    scanf ("%d", &number);
    size = find_digits (number);
    int array [size];
    for (int x = 0; x < size; ++x) {
        array[x] = (number / (int) (pow (10, x))) % 10;
    } for (int y = 0; y < size; ++y) {
        total = total + (array [y] * ((int) (pow (base, y))));
    }
    to_second_base (total, base2);
} int main () {
    main_algorithm ();
    return 0;
}
