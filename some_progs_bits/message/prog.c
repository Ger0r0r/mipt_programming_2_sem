#include <stdio.h>

int main ()
{
	char b;
	char p = 0;
	int lon = 0;
	while (scanf("%hhi", &b) != EOF)
	{	
		for (int i = 0; i < 3; ++i)
		{
			++lon;
			if (lon > 8)
			{
				printf("%hhu ", p);
				p = 0;
				lon -= 9;
				--i;
				continue;
			}
			else
			{
				p = p | (((b>>(2-i)) & 1)<<(8 - lon)) ;
			}
		}	
	}

	printf("%hhu\n", p);
	return 0;
}