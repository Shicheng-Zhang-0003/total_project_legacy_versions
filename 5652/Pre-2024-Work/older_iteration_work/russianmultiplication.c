/* This is a C program designed to be a calculator for the old method
* of Russian Peasant multiplication algorithm. This algorithm, a 
* derivative of the ancient Egyptian multiplication algorithm, is 
* very useful for instantly or very quick calculations of values of
* extremely big numbers. The algorithm itself is as follows:
*
* First, imagine we are doing 45 x 23
*
* Secondly, for the first factor, divide it by two continously until 1
* and we should get these values:
* 
* 45, 22, 11, 5, 2, 1 (ignore the remainders if there are remainders)
*
* These values are stored inside the attr attribute string(int)
*
* Thirdly, do the same with the other factor, only in reverse(multiply)
* and do it the SAME number of times that you divided the first factor
* by.
*
* You divided the first factor 6 times.
*
* so 6 times multiplication of 23 is:
* 23, 46, 92, 184, 368, 736.
*
* This is stored in attr2[]
* 
* Fourthly, if the value in the first attr attribute can be divided by 2
* (eg: attr[1] here is 22, can be divided by 2), then using attr3, it is
* nullified from the eventual calculation(part of algorithm).
*
* Which values will be eliminated and which will be used are pinpointed using attr3[]
*
* After, all you need to do is to add the values that are needed to be added 
* in the calculation(if(attr3[x] == 1) add the values of attr2[x] where attr3[x] == 1)
*
* Please note the this program cannot deal with negative inputs as of yet, a improved 
* version which can will be uploaded soon.
*
* Please no not copy and paste, this has been copyrighted.
*
* Copyright 2023, Shicheng.Z July 23th 2023.
*/
#include <stdio.h>
int main()
{
	int multi1, multi2;
	printf("Enter the first factor:");
	scanf("%d",&multi1);
	printf("Enter the second factor:");
	scanf("%d",&multi2);
	int attr[multi1], attr2[multi2];
	for(int s = 0;s < multi1;s++)
	{
		attr[s] = 0;
	}
	for(int d = 0;d < multi2;d++)
	{
		attr2[d] = 0;
	}
	int counter = 1, counter2 = 1;
	attr[0] = multi1;
	attr2[0] = multi2;
	while (1)
	{
		attr[counter] = attr[counter - 1] / 2;
		if(attr[counter] == 1)
		{
			break;
		}
		else
		{
			counter++;
		}
	}
	while (1)
	{
		attr2[counter2] = attr2[counter2 - 1] * 2;
		if(counter2 == counter)
		{
			break;
		}
		else
		{
			counter2++;
		}
	}
	int attr3[multi1 + multi2];
	for(int x = 0;x < multi1 + multi2;x++)
	{
		if(attr[x] == 0)
		{
			attr3[x] = 0;
		}
		else
		{
			if(attr[x] % 2 != 0)
			{
				attr3[x] = 1;
			}
			else
			{
				attr3[x] = 0;
			}
		}
	}
	int result = 0;
	for(int o = 0;o < multi2;o++)
	{
		if(attr3[o] == 1)
		{
			result = result + attr2[o];
		}
	}
	printf("Your russian multiplied result from %d x %d is: %d\n",multi1, multi2,result);
}
