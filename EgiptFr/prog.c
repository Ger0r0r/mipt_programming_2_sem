#include <stdio.h>
#include <stdlib.h>

int main ()
{
	unsigned long long int	up, 
							dn,
							m;

	scanf ("%llu %llu", &up, &dn);

	while (up > 1)
	{
		//printf("upper = %u downer = %u\n", up, dn);

		if (dn % up == 0)
		{
			printf("%llu\n", dn / up);
			break;
		}

		m = dn / up + 1;

		printf("%llu\n", m);

		up = up * m - dn;
		dn = dn * m;		
	}

	if (up == 1)
		printf("%llu\n", dn);

	return 0;
}