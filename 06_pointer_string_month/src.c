// Using string array  to output month name in English

#include <stdio.h>
int main(int argc, char const *argv[])
{
	// Define a pointer array to store month name
	char *month[12] = {"January","February","March","April","May","June","July","Auguest","September","October","November","December"};
	// Define var to represent month
	int num;
	printf("Please enter the month number:");
	scanf("%d",&num);
	// The sequence in array is less 1 than number
	num--;

	// Invalidate input division
	if( (num < 0) | (num > 11) )
	{
		printf("Invalidate month !\n");
		return -1;
	}
	


	printf("The month's name is :");
	printf("%s\n",*(month+num) );

	return 0;
}