#include <stdio.h>

int main ()
{
	int A[4] = {0};

	int a = -1,
	b = 0,
	c = 0;

	while (a != 0)
	{
		scanf("%i", &a);

		switch (a)
		{
		case 1:
			scanf("%i %i", &b, &c);
			A[b-5] = (A[b-5] + A[c-5]) % 256;
			break;
		case 2:
			scanf("%i %i", &b, &c);
			A[b-5] = (A[b-5] - A[c-5]) % 256;
			break;
		case 3:
			scanf("%i %i", &b, &c);
			A[b-5] = c;
			break;
		case 4:
			printf("%i %i %i %i\n", A[0], A[1], A[2], A[3]);
			break;
		default:
			break;
		}
	}

	return 0;

}