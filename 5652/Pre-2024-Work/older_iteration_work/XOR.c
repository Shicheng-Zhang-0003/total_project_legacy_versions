/* This is a C program designed to be a basic bitwise XOR function with out using
* the ^ sign(which is the bitwise XOR sign in C code). It converts the decimal 
* decimal numbers into reversed binary, which then goes through the XOR calculation,
* which is that if the bits of binary are the same in both binary numbers, say if:
* 
* #DEF attr1[x] representing 5 in decimal, attr2[x] representing 3 in decimal
* 
* attr1 = {1, 0, 1} (5 in decimal)
* attr2 = {1, 1} (3 in decimal)
* 
* the induvidual integers in the array will combine for form a new number, which forms
* binary integer, which goes like this:
*
* attr1 = {1, 0, 1}
* attr2 = {0, 1, 1} (0 was added to make the calculation performable as XOR requires arrays of equal length).
* XOR(attr1[], attr2[]) = (in pseudocode)
*	if(attr1[n] == attr2[n])
*	ex: attr1[n] == 1 && attr2[n] == 1
* 	then attr3[n](result of calculation) = 0
*	else
*	ex: attr1[n] == 0 && attr2[n] == 1
*	then attr3[n] = 1;
* 	repeat until n == x, then break(for function in C)
* 
* so here:
* 1 0 1
* 0 1 1
*_______
* 1 1 0
* so attr3 = {1, 1, 0}(6 in binary)
*
* then the new binary number is converted back to decimal, using the conversion algorithm: sumof((x)2 = digits of x * their respective power of 2 until):
* (110)2 --->
* (110)2 = (0 * 2 to power of 0) + (1 * 2 to power of 1) + (1 * 2 to power of 2)(rep until exponent = x)
* (110)2 = 0 + 2 + 4
* (110)2 = (6)10
* 
* Please note that this is only a first version, and this program is unable to take anything other than positive integers, if letters are entered,
* The program will enter a while loop, printing out all numbers from 0~25, and 0 beside it, else if negative integers are entered, the program will freeze.
* A version capable of running on negative inputs will be coming soon.
*
* Please also DO NOT copy and paste this program and claim credit, if you wish to use this algorithm, please leave a reference in your own program.
* Copyrighted on May 5th, 2023. Shicheng.Z
*/
#include <stdio.h>
int power(int base, int exponent);
int largest(int number, int number2);
int power(int base, int exponent)
{
	int base2 = 1;
	if(exponent == 0)
	{
		return base;
	}
	base2 = base;
	for(int uu = 0;uu < exponent - 1;uu++)
	{	
		base2 = base * base2;
	}
	return base2;
}
int largest(int number, int number2)
{
	if(number == number2)
	{
		return number;
	}
	else if(number < number2)
	{
		return number2;
	}	
	else
	{
		return number;
	}
}
int main()
{
	int number, number2;
	printf("Enter your first number:");
	scanf("%d",&number);
	printf("Enter your second number:");
	scanf("%d",&number2);
	int spare = largest(number, number2);
	int attr[spare], attr2[spare], attr3[spare], attr4[spare];
	for(int a = 0;a < spare;a++)
	{
		attr[a] = 0;
	}
	for(int aa = 0;aa < spare;aa++)
	{
		attr2[aa] = 0;
	}
	for(int aaa = 0;aaa < spare;aaa++)
	{
		attr3[aaa] = 0;
	}
	for(int aaaa = 0;aaaa < spare;aaaa++)
	{
		attr4[aaaa] = 0;
	}
	int def = 0, def2 = 0, def3 = 0, def4 = 0, plus = 0, plus2 = 0, plus3 = 0;
	//Convert Entries into binary numbers.
	while (1)
	{
		if (def == 1)
		{
			break;
		}
		else
		{
			if (number == 1)
			{
				def = 1;
			}
			attr[plus] = number % 2;
			number = number / 2;
		}
		plus = plus + 1;
	}
	while (1)
	{
		if (def2 == 1)
		{
			break;
		}
		else
		{
			if (number2 == 1)
			{
				def2 = 1;
			}
			attr2[plus2] = number2 % 2;
			number2 = number2 / 2;
		}
		;
		plus2 = plus2 + 1;
	}
	//Do the XOR calculation.
	for(int sxsx = 0;sxsx < spare;sxsx++)
	{
		if(attr[sxsx] == attr2[sxsx])
		{
			attr3[sxsx] = 0;
		}
		else
		{
			attr3[sxsx] = 1;
		}
	}
	//Reconfigure converted binary to decimal.
	attr4[0] = attr3[0] * 1;
	for(int sks = 1;sks < spare;sks++)
	{
		attr4[sks] = attr3[sks] * power(2, sks);
	}
	int result = 0;
	//Combine for final result.
	for(int sks1 = 0;sks1 < spare;sks1++)
	{
		result = result + attr4[sks1];
	}	
	printf("%d\n",result);
}
