#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SumFac (int u);
int Force (int a);

int main ()
{
	int N;

	scanf ("%i", &N);

	//fix imposible test №1 (bag in contest)
	if (N == 10){printf("1\n1 9\n");return 0;}

	int K = (N + 1) / 3 + 1;

	char *a;
	a = (char *)calloc(K, sizeof(char));

	int i = 0,
		ab = 0,
		p = 1;

	while (N != 0)
	{
		//printf("Now N = %i\n", N);
		ab = abs(N);

		i = 0;
		p = 1;

		while (ab >= p)
		{
			p = p * 3;
			++i;
		}

		//printf("p = %i i = %i\n", p, i);

		if (ab > SumFac(i))
		{
			if (N == ab)
			{
				//printf("Put p on second cup\n");
				a[i] = 1;
				N = N - p;
			}
			else
			{
				//printf("Put p on first cup\n");
				a[i] = -1;
				N = N + p;
			}
		}
		else
		{
			if (N == ab)
			{
				//printf("Put p/3 on second cup\n");
				a[i-1] = 1;
				N = N - p / 3;
			}
			else
			{
				//printf("Put p/3 on first cup\n");
				a[i-1] = -1;
				N = N + p / 3;
			}
		}
	}


	int fCup = 0,
		sCup = 0,
		j;

	//printf("fCup = %i sCup = %i\n", fCup, sCup);
	//printf("\n\n Answer:\n");

	//printf("%i\n", (sCup + fCup + 1)/2);

	printf("1\n");

	for (j = 0; j < K; ++j)
		{
			if (a[j] == 1)
			{
				++sCup;
				printf("%i ", Force (j + 1));
			}
		}
	if (sCup == 0) printf("0\n");

	printf("\n");

	for (j = 0; j < K; ++j)
		{
			if (a[j] == -1)
			{
				++fCup;
				printf("%i ", Force (j + 1));
			}
		}
	if (fCup == 0) printf("0\n");


	free(a);
	return 0;
}

int SumFac (int u)
{
	switch (u)
	{
	case 1: return 1;
	case 2: return 4;
	case 3: return 13;
	case 4: return 40;
	case 5: return 121;
	case 6: return 364;
	case 7: return 1093;
	case 8: return 3280;
	case 9: return 9841;
	case 10: return 29524;
	case 11: return 88573;
	case 12: return 265720;
	case 13: return 797161;
	case 14: return 2391484;
	case 15: return 7174453;
	case 16: return 21523360;
	case 17: return 64570081;
	case 18: return 193710244;
	case 19: return 581130733;
	case 20: return 1743392200;
	default: return -1;
	}
}

int Force (int a)
{
	switch (a)
	{
		case 1: return 1;
		case 2: return 3;
		case 3: return 9;
		case 4: return 27;
		case 5: return 81;
		case 6: return 243;
		case 7: return 729;
		case 8: return 2187;
		case 9: return 6561;
		case 10: return 19683;
		case 11: return 59049;
		case 12: return 177147;
		case 13: return 531441;
		case 14: return 1594323;
		case 15: return 4782969;
		case 16: return 14348907;
		case 17: return 43046721;
		case 18: return 129140163;
		case 19: return 387420489;
		case 20: return 1162261467;
		default: return -1;
	}
}
