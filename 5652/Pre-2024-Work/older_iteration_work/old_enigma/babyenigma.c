/* This is an minorly updated version of the original enigma code I 
 * coded which adds some security to the randomness of the final 
 * printout as well as a major technical update on the input. This 
 * final update also cures an unforseen bug with the program that I 
 * had not discovered before hand with the original algorithm.
 *
 * March 28th.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int prime(int l);
int smallest_factor(int s);
int prime(int l)
{
        int j = 0;
        if((l == 0) || (l == 1) || (l < 0) || (l == 2))
        {
                return j;  
        }
        else
        {
                for(int g = 1;g <= l;g++)
                {
                        if((l % g) == 0)
                        {
                                j++;
                        }
                }
        }
        ;
        if(j == 2)
        {
                j = 0;
        }
        return j;
}
int smallest_factor(int s)
{
        int smallest;
        for(int h = s;h >= 2;h--)
        {
                if(s % h == 0)
                {
                        smallest = h;
                }
        }
        return smallest;
}
int main()
{
        int number;
        printf("Enter any number:");
        scanf("%d",&number);
        char string[number];
        int attr[number];
        int attr2[number];
        int attr3[number];
        int attr4[number];
        int attr5[number];
        int scrambler;
        printf("Welcome to the new Enigma Machine.\n");
	sleep(1);
        printf("Enter string:");
        scanf("%s",string);
        
        for(int bbb = 0;bbb < number;bbb++)
        {
                attr[bbb] = string[bbb];
        }
        printf("Enter the scramble number:");
        scanf("%d",&scrambler);
        for(int h7 = 0;h7 < number;h7++)
        {
                attr5[h7] = attr[h7];
        }
        for(int h1 = 0;h1 < number;h1++)
        {
                attr2[h1] = 0;
        }
        for(int h2 = 0;h2 < number;h2++)
        {
                attr3[h2] = 0;
        }
        for(int h3 = 0;h3 < number;h3++)
        {
                attr4[h3] = 0;
        }
        int e = 0;
        while (1)
        {
                if(e == number)
                {
                        break;
                }
                else
                {
                        if(prime(attr[e]) == 0)
                        {
                                attr2[e] = attr[e];
                                attr[e] = 0;
                        }
                        else
                        {
                                attr3[e] = smallest_factor(attr[e]);
                                attr4[e] = attr[e] / attr3[e];        
                        }
                        e++;
                }
        }
        printf("\n");
        for(int a = 0;a < number;a++)
        {
                if(attr[a] == 0)
                {
                        printf("0 ");
                }
                else
                {
                        printf("1 ");
                }
        }
        printf("\n");
        for(int a2 = 0;a2 < number;a2++)
        {
                if(attr2[a2] == 0)
                {
                        printf("0 ");
                }
                else
                {
                        printf("%d ",attr2[a2] + scrambler);
                }
        }
        printf("\n");
        for(int a3 = 0;a3 < number;a3++)
        {
                printf("%d ",attr3[a3]);
        }
        printf("\n");
        for(int a2 = 0;a2 < number;a2++)
        {
                if(attr2[a2] != 0)
                {
                        printf("1 ");
                }
                else
                {
                        printf("0 ");
                }
        }
        printf("\n");
        for(int a4 = 0;a4 < number;a4++)
        {
                printf("%d ",attr4[a4]);
        }
        printf("\n");
        printf("%d\n\n",scrambler);
        printf("%s",string);
        printf("\n\n");
}
