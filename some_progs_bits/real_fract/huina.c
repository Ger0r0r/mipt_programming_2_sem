#include <stdio.h>
#include <string.h>

void printBIT(char t);

int main()
{
	float s;

	for (int i = -128; i < 127; ++i)
	{
		s = i;
		char *a = &s;
	
		for (int j = 0; j < 4; ++j)
		{
			printBIT(a[j]);

			printf("");
		}

		printf(" --- %i\n", i);
	}

	

}

void printBIT(char t)
{
	int p = 0;
	for (int i = 7; i >= 0; --i)
	{
		(((t>>i) & 1) != 0) ? printf("1") : printf("0");
	}
}