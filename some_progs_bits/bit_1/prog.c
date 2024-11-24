#include <stdio.h>

int main()
{
	char a;

	scanf ("%hhx", &a);

	if (a & 128 == 128)
	{
		printf("ma\n");	
	}
	else 
		printf("fe\n");
	return 0;
}