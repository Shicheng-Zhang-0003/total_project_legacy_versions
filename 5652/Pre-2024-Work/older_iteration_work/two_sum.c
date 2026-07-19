/* This is a C program to determine if two numbers in a array
* add up to the same target number which all are inputted. 
* This program can run on all integer inputs, negative or
* positive, and can still generate the correct results.
* All you need if you wish for float or decimal inputs
* is just to convert everything that runs on INT to the 
* FLOAT data type, just insure that when you input the size
* of the attribute, that bit will remain to be an positive 
* integer as otherwise the program cannot run.
*
* This HAS been copyrighted, do not copy.
*
* Copyright 2023, July 24th, 2023.
*/
#include <stdio.h>
int main()
{
        int number, target;
        printf("Enter the size of the attribute:");
        scanf("%d",&number);
        int attr[number];
        int attr2[number];
        int attr3[number][2];
        printf("Enter your target number:");
        scanf("%d",&target);
        for(int s = 0;s < number;s++)
        {
                printf("Enter the attribute:");
                scanf("%d",&attr[s]);
                attr2[s] = 1;
                attr3[s][0] = 0;
                attr3[s][1] = 0;
        }
        int v = 0;
        for(int d = 0;d < number;d++)
        {
                for(int p = 0;p < number;p++)
                {
                        if((attr2[d] != 0) && (attr2[p] != 0) && (d != p))
                        {
                                if(attr[d] + attr[p] == target)
                                {
                                        attr3[v][0] = attr[d];
                                        attr3[v][1] = attr[p];
                                        attr2[d] = 0;
                                        attr2[p] = 0;
                                        v++;
                                }
                        }
                }
        }
        for(int a = 0;a < v;a++)
        {
                printf("{%d, %d}\n",attr3[a][0], attr3[a][1]);
        }
}
