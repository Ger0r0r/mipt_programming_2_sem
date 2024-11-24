#include <stdio.h>

int main()
{
	char *Gen[2] = {"fe", "ma"};
	char *Int[2] = {"du", "cl"};
	char *Hat[2] = {"nh", "ha"};
	char *Tro[2] = {"sk", "tr"};
	char *Hai[4] = {"bn", "rd", "bw", "bk"};
	char *Eye[4] = {"bu", "ge", "gy", "da"};

	char a;

	scanf("%hhx", &a);

	printf("%s ", Gen[(a & 1)]);
	printf("%s ", Int[(a & 2)>>1]);
	printf("%s ", Hat[(a & 4)>>2]);
	printf("%s ", Tro[(a & 8)>>3]);
	printf("%s ", Hai[(a & 48)>>4]);
	printf("%s\n", Eye[(a & 192)>>6]);

	return 0;
}