#include <stdio.h>

int main ()
{
	int s[4];
	int d[4];

	char fl = 1;

	scanf("%i.%i.%i.%i", &s[0], &s[1], &s[2], &s[3]);

	scanf("%i.%i.%i.%i", &d[0], &d[1], &d[2], &d[3]);

	if (d[0] != 255)
		fl = 0;
	(fl == 1) ? printf("%i.", s[0]) : printf("255.");
	if (d[1] != 255)
		fl = 0;
	(fl == 1) ? printf("%i.", s[1]) : printf("255.");
	if (d[2] != 255)
		fl = 0;
	(fl == 1) ? printf("%i.", s[2]) : printf("255.");
	if (d[3] != 255)
		fl = 0;
	(fl == 1) ? printf("%i\n", s[3]) : printf("255\n");

	return 0;
}