#include <iostream>		/* cin, cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
int main(int argc, char **argv)
{
	int nums[3], i, total;
	char dummy;

	srand(time(NULL));
	total = 0;
	for(i=0; i<3;++i)
		nums[i] = rand()%6+1;
		if(argc == 1)
		{
			for(i=0;i<3;i++)
			{
				std::cout << nums[i] << " ";
				total+=nums[i];
			}
			std::cout << " = " << total << std::endl;
		}
	return 0;
}

