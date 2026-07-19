/* This is a simple C program esigned to be a factorial, nCr, and nPr calculator.
* The algorithm for the factorial is as below, as well as the equation for the 
* nCr and the nPr This version can only handle positive inputs, negative inputs 
* will return erratic and wrong results.
*
* please no copying.
*
* Shicheng.Z july 16th
*/
#include <stdio.h>
int factorial(int number);
int factorial(int number)
{
        if(number == 0)
        {
                number = 1;
                return number;
        }
        for(int h = number - 1;h > 0;h--)
        {
                number = number * h;
        }
        return number;
}
int main()
{
        int number, number2;
        printf("Enter the first number:");
        scanf("%d",&number);
        printf("Enter the second number:");
        scanf("%d",&number2);
        int number3 = factorial(number) / (factorial(number2) * factorial(number - number2));
        int number4 = factorial(number) / factorial(number - number2);
        printf("nCr (%d, %d) = %d. nPr (%d, %d) = %d\n",number, number2, number3, number, number2, number4);
        printf("%d! = %d, %d! = %d\n",number,factorial(number),number2,factorial(number2));
}
