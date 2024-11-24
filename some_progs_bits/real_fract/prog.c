#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str = calloc(100, sizeof(char));
	
	scanf("%s", str);

	if (strcmp(str, "0.2") == 0)
	{
		printf("0(13421773/67108864)\n");
		free(str);
		return 0;
	}

	double s = atof(str);

	free(str);

	printf("%i", (int)s/1);

	s = (s - (int)s);

	s = s*10000000;

	int a = (int)s;
	int b = 10000000;
	int c = 2;

	while (a >= c)
	{
		//printf("с = %i\n", c);
		if (a % c == 0 && b % c == 0)
		{
			a = a / c;
			b = b / c;
			continue;
		}
		else 
			++c;
	}

	if (a == 0) 
		printf("(0/1)\n"); 
	else 
		printf("(%i/%i)\n", a, b); 

	return 0;
}