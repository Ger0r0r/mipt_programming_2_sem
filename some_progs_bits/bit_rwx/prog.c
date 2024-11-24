#include <stdio.h>

int main ()
{
	char st[9];

	int cod;

	scanf("%o", &cod);

	//printf("%i\n", cod);

	for (int i = 0; i < 9; ++i)
	{
		st[8 - i] = 1 & (cod>>i);
	}

	//printf("%i%i%i%i%i%i%i%i%i\n",st[0],st[1],st[2],st[3],st[4],st[5],st[6],st[7],st[8]);

	for (int i = 0; i < 9; ++i)
	{
		if (i % 3 == 0 && st[i])
			printf("r");
		else
		if (i % 3 - 1 == 0 && st[i])
			printf("w");
		else
		if (i % 3 - 2 == 0 && st[i])
			printf("x");
		else
			printf("-");
	}

	printf("\n");
}