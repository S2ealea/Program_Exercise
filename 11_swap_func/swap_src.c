/*Swap function design*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	#define SWAP_V2(a,b) (a += b, b = a - b, a -= b)


	int test_1 = 10;
	int test_2 = 100;
	// Swaped 
	SWAP_V2(test_1,test_2);
	printf("Now the test_1 is %d ,test_2 is %d\n",test_1,test_2);

	// Swaped itself
	SWAP_V2(test_1,test_1);
	printf("Now the test_1 is %d \n",test_1);

	return 0;
}