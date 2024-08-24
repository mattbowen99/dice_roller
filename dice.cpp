/************************************/
/* Title: dice						*/
/* Version: 1.2						*/
/*	Added 1dn roller				*/
/* Purpose: Roll gurps-style dice.	*/
/* Functionality: Call and recieve	*/
/*	3d6 rolls and a sum of their	*/
/*	values.							*/
/*	Call with an integer n argument	*/
/*	between 2 and 999 and recieve	*/
/*	1dn roll.						*/
/* Functions: isNumber, inRange		*/
/************************************/

#include <iostream>		/* cin, cout */
#include <stdlib.h>     /* srand, rand, strtod*/
#include <time.h>       /* time */
#include <string.h>		/* strlen */
#define DIEDIGITS 4

int main(int argc, char **argv)
{
	bool isNumber(char*);
	bool inRange(double);

	int nums[4], i, total;
	char dummy;
	char* dumpnt;
	char die[DIEDIGITS];

	srand(time(NULL));
	total = 0;

	try
	{
	if(argc == 1)
	{
		for(i=0; i<3;++i)
			nums[i] = rand()%6+1;
		for(i=0;i<3;i++)
		{
			std::cout << nums[i] << " ";
			total+=nums[i];
		}
		std::cout << " = " << total << std::endl;
	}
	else if(argc == 2)
	{
		strncpy(die,argv[1],DIEDIGITS);
		if((isNumber(die)) && (inRange(strtod(die,&dumpnt))))
		{
			std::cout << "1D" << die << ": ";
            			std::cout << rand()%(int)(strtod(die,&dumpnt))+1;
			std::cout << std::endl;
		}
		else
			throw 20;
	}
	else
		throw 10;
	}
	catch(int x)
	{
		switch(x)
		{
			case 10:
				std::cout << "Only one argument is allowed"
						  << std::endl;
				break;
			case 20:
				std::cout << "Input must be an integer between "
						  << "1 and 999" << std::endl;
				break;
			default:
				std::cout << "Unknown Error" << std::endl;
		}
	}

	return 0;
}

bool isNumber(char* in)
{
	int i;
	for(i=0; in[i] != '\0'; i++)
	{
		if((in[i] < '0') || (in[i] > '9'))
			return false;
	}
	return true;
}

bool inRange(double in)
{
	if((in >= 2) && (in <=100))
		return true;
	return false;
}
