#include <stdio.h>

int main()
{
	char a;
	char b = 4;

	scanf ("%hhx", &a);

	if ((a & b) == b)
	{
		printf("ha\n");	
	}
	else 
		printf("nh\n");
	return 0;
}