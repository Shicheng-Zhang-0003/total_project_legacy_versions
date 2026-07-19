/*This is a simple C program that is designed to be a effective 
# numberline algorithm/program for use in mathematics and other
# things that require excessive counting. Most of the warnings 
# about the program function and potential occurences are included
# in the prompt itself, however, there is a serious risk of 
# of your computer crashing, especially if it is an older one.
# Mixing numerical, letter, and symbol inputs will return an
# infinite printout of the prompt, which can also cause severe 
# problems to your computer if left unchecked.
#
# The Maximum number is the number which the program begins its
# counting at, and it uses the counternumber to skip count all 
# the way until the end number.
#
# Don't try to copy and paste it please >:(
#
# 17th March, 2023.  Shicheng.Z
*/
#include <stdio.h>
#include <unistd.h>
int prime(int number);
int prime(int number)
{
    int result = 2;
    int carrier = 0;
    for(int y = 2;y < number;y++)
    {
        if(number % y == 0)
        {
            result++;
        }
    }
    if(result == 2)
    {
        return carrier;
    }
    else
    {
        carrier++;
        return carrier;
    }
}
int main()
{
    int number;
    int number2;
    int end;
    int decision;
    head:
    printf("Warnings about Program Function:\n\n");
    printf("Negative numbers will always read as prime numbers.\n");
    printf("Do not Enter a negative Counternumber.\n");
    printf("Counternumber means what number are you skipcounting by, such as by 4.\n");
    printf("The program runs backwards, the largest number will be printed first, and counted backwards to the smallest.\n");
    printf("Do not Enter Counternumber(Skip Counting by counternumber)lower than 1, that will trigger an infinite while loop.\n");
    printf("Doing the above may also crash/glitch your computer, trigger seg fault, or output incorrect answers with certain inputs.\n");
    printf("Entering non integer inputs will result in output of (0), 0, and 0.\n");
    printf("Maximum number digits are restricted to 9, beyond will cause incorrect outputs.\n\n");
    printf("Please Enter Maximum number:");
    scanf("%d",&number);
    printf("Please Enter Counternumber:");
    scanf("%d",&number2);
    printf("Please Enter End number:");
    scanf("%d",&end);
    printf("\n");
    if(number2 <= 0)
    {
        printf("Do you wish to continue?(0 = no, any other number = yes)");
        scanf("%d",&decision);
        if(decision == 0)
        {
            goto head;
        }
    }
    int prime_ = 0;
    int composite_ = 0;
    int f = 0;
    int z = number;
    int a;
    while(1)
    {
        if(f == 1)
        {
            break;
        }
        else
        {
            while(1)
            {
                if(number <= end)
                {
                    if(number < end)
                    {
                        printf("(%d)\n",end);
                        printf("\nThis Skip Counting Pattern Goes past the End number.");
                        f++;
                        break;
                    }
                    else
                    {
                        printf("%d\n",number);
                        f++;
                        break;
                    }
                }
                else
                {
                    if(number != 1)
                    {
                        a = prime(number);
                        if(a == 0)
                        {
                            prime_++;
                        }
                        else
                        {
                            composite_++;
                        }
                        printf("%d ",number);
                        number = number - number2;
                        z = number;
                    }
                    else if(number == 1)
                    {
                        printf("%d ",number);
                        number = number - number2;
                        z = number;
                    }
                    else
                    {
                        ;
                    }
                }
            }
        }
    }
    printf("\n");
    printf("Total Number of Prime Numbers(Discounting 0 and 1): %d\n",prime_);
    printf("Total Number of Composite Numbers: %d\n",composite_);
}
