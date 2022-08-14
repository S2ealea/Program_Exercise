// gcc -fsanitize=address -fno-omit-frame-pointer  -g
// Has the wrong output

#include "LinkList.h"

char array[] = {'a','b','c','b','a','d'};
bool isPalindrome(LinkList* list, int length)
{
	int i ;
	char buff1[length],buff2[length];
	ElemType e;

	for (int i = 1; i <= length; i++)
	{
		GetListElem(list,i,e);
		buff1[i-1] = e;		//The positive sequence string
		buff2[length-i] = e; //The oppsitive sqeuenct string
	}

	i = 0;
	while(i < length)
	{
		// Compare the two array
		if( buff1[i] == buff2[i]) 
		{
			i++;
		}
		else
		{
			return false;
		}
	}

	return true;

}



int main(int argc, char const *argv[])
{
	LinkList* list;
	int length = sizeof(array)/sizeof(array[0]);
	CreateListTail(list,array,length);

	if (isPalindrome(list,length))
		printf("isPalindrome\n");
	else
		printf("IsNotPalindrome\n");

	return 0;
}

