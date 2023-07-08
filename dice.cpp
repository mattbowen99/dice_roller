#include <iostream>		/* cin, cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
int main(int argc, char **argv)
{
	int nums[3], i, total;
	char dummy;

	srand(time(NULL));
	while()
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
	}
	return 0;
}

