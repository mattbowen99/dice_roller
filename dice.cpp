#include <iostream>		/* cin, cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>		/*strcpy*/


class asciiArt{
	protected:
		char *art;

	public:
		int printArt();
};

int asciiArt::printArt()
{
	std::cout << art << "\n";
	return 0;
}

class diceArt : public asciiArt{
	public:
		diceArt();
};

diceArt::diceArt()
{
	art = new char[202];
	strcpy(art,R"(
       .-------.    ______
      /   o   /|   /\     \
     /_______/o|  /o \  o  \
     | o     | | /   o\_____\
     |   o   |o/ \o   /o    /
     |     o |/   \ o/  o  /
jgs  '-------'     \/____o/)");

	return;
}


int main(int argc, char **argv)
{
	int nums[3], i, total;
	char dummy, in = '\0';

	diceArt logo;

	logo.printArt();

	srand(time(NULL));
	do
	{
		total = 0;
		for(i=0; i<3;++i)
			nums[i] = rand()%6+1;
		if(argc == 1)
		{

			//print dice grahics before populating them with real numbers
			for(i=0;i<3;i++)
			{
				total+=nums[i];
			}
			//std::cout << nums[i] << " ";
			std::cout << "total = " << total << std::endl;
		}
		std::cin >> in;
	}while(in == 'r');
	return 0;
}

