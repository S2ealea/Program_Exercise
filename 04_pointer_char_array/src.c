// String  and array

#include <stdio.h>
int main()
{
	char a[] = "I am a programmer";
	char b[20];
	int i ;
	for (i = 0; *(a+i) !='\0';i++)
	*(b+i) = *(a+i);
	*(b+i) = '\0';		// Termination character

	printf("string a is :%s \n", a);
	printf("string b is :");
	for (i=0; b[i] != '\0';i++)
		printf("%c",b[i] );
	printf("\n");

	char c[] = "I am a network programmer";
	char d[20];
	char *p1;
	char *p2;
	p1 = c;
	p2 = d;
	for (;*p1 != '\0';p1++,p2++)
		*p2 = *p1;
		*p2 = '\0';  // Termination character

	printf("string c is :%s\n",c );
	printf("string d is :%s\n",d );

	printf("\n");


	return 0;

}