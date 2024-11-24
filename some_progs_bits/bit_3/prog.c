#include <stdio.h>

int main()
{
	char *b[4] = {"bn","rd","bw","bk"};
	char a;

	scanf("%hhx", &a);

	printf("%s\n", b[(a & 48)>>4]);

	return 0;
}