/*C free() function test */

#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char const *argv[])
{
	int *value = malloc(sizeof(int)*5);
	value[4] = 100;
	free(value);    //free the memory


/*	Test here
*	free() function just set a short part of 
*	the parameter address into zere .
*	if the address is long enough,there will be
*	a huge risk.
*/
	printf("%d\n",value[4] );

	return 0;
}