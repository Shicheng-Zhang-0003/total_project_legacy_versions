/* This is a C program designed to be a calculator for binomial distribution 
* and probability calculations using a pascals triangle as the coefficient finder
* and also solving the probability by employing the sum of all the possibilities 
* as calculated. There is also a function capable of running probability calculations
* whose singualr theoretical probability is not that of 50% or 0.5, which runs on the 
* binomial formula conerning probability and is supplemented by a nCr and a factorial 
* sub-function for these calculations.
*
* The update that will enable the program to graph the results will be coming shortly.
*
* Please do not copy and paste :(
*
* Shicheng.Z  OG: July 15th, 2023. UPDATED July 17th, 2023
*/
#include <stdio.h>
#include <math.h>
int factorial(int number);
int nCr(int number, int number2);
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
int nCr(int number, int number2)
{
	return factorial(number) / (factorial(number2) * factorial(number - number2));
}
int main()
{
	int og_total, choice;
	float prob;
	printf("Enter the total amount of choices:");
	scanf("%d",&og_total);
	printf("Enter the choice:");
	scanf("%d",&choice);
	printf("Enter the probability for the event in question:");
	scanf("%f",&prob);
	if((prob > 0) && (prob < 1))
	{
		if(prob == 0.5)
		{
			int total = og_total + 1;
			int attr[total][total];
			for(int s = 0;s < total;s++)
			{
				for(int u = 0;u < total;u++)
				{
					attr[s][u] = 0;
				}
			}
			attr[0][0] = 1;
			attr[1][0] = 1;
			attr[1][1] = 1;
			for(int x = 2;x < total;x++)
			{
				for(int a = 0;a < total;a++)
				{
					if(a == 0)
					{
						attr[x][a] = 1;
					}
					else
					{
						attr[x][a] = attr[x - 1][a] + attr[x - 1][a - 1];
					}
				}
				printf("\n");
			}
			int result = attr[total - 1][0];
			for(int l = 1;l < total;l++)
			{
				result = attr[total - 1][l] + result;
			}
		printf("Getting a %d chosen results out of %d og tosses with %f as the singular probability in 2 mutually exclusive outcomes is %d / %d or %lf percent\n",choice,og_total,prob,attr[total - 1][choice],result,((double)attr[total - 1][choice] / (double)result) * 100);}
		else
		{
			double answer;
			answer = nCr(og_total,choice) * pow(prob,(double)choice) * pow((double)1 - prob,(double)(og_total - choice));
			printf("Probability is equal to: %lf\n",answer);
		}
	}
}

