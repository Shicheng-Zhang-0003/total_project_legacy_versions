/*This is a simple C program to print out a right triangle of desired height
# and inputted amount of stars to be printed. Say if you enter a 5 on the first input
# prompt, and a 1 on the second input prompt, a upside-down triangle that looks
# like this will appear:
#
# *
# **
# ***
# ****
# *****
#
# However, if you enter a 0 on the second input prompt, it gives you:
# 
# *****
# ****
# ***
# **
# *
# 
# And if you enter any other number the program will automatically exit 
# due to the lack of a decision.
#
# Please do not copy and paste.
# May 16th, 2023.  Shicheng.Z
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
        int number, numbers;
        printf("How many stars are there to be in the first/last row:");
        scanf("%d",&number);
        printf("Is it inverted or upright:");
        scanf("%d",&numbers);
        int origin = 1;
        if(numbers == 0)
        {
                origin = number;
                for(int h = 0;h < number;h++)
                {
                        for(int h1 = 0;h1 < origin;h1++)
                        {
                                printf("*");
                        }
                        printf("\n");
                        origin--;
                }
        }
        else if(numbers == 1)
        {
                for(int h2 = 0;h2 < number;h2++)
                {
                        for(int h1 = 0;h1 < origin;h1++)
                        {
                                printf("*");
                        }
                        printf("\n");
                        origin++;
                }
        }
        else
        {
                exit(0);
        }
}
