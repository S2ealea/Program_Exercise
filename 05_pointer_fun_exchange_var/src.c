// Exchange 2 value by function which parameter is pointer

#include <stdio.h>
int main()
{
	void swap ( int *pointer1, int *pointer2 );
	int *p1;
	int *p2;
	int a;
	int b;

	printf("Please enter two interger number:");
	scanf("%d,%d",&a,&b);
	p1 = &a;
	p2 = &b;

	if ( a < b )
		swap (p1,p2);
	printf("max = %d, min = %d\n",a,b);

	return 0;
}

void swap ( int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}