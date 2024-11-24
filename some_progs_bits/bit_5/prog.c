#include <stdio.h>
#include <string.h>

int main()
{
	unsigned char mas = 0;

	char ss[4] = {0};

	while (scanf("%s", ss) != EOF)
	{

		mas = (strcmp(ss, "ma") == 0) ? mas | 1 : mas;
		mas = (strcmp(ss, "cl") == 0) ? mas | 2 : mas;
		mas = (strcmp(ss, "ha") == 0) ? mas | 4 : mas;
		mas = (strcmp(ss, "tr") == 0) ? mas | 8 : mas;
		mas = (strcmp(ss, "rd") == 0) ? mas | 16 : mas;
		mas = (strcmp(ss, "bw") == 0) ? mas | 32 : mas;
		mas = (strcmp(ss, "bk") == 0) ? mas | 48 : mas;
		mas = (strcmp(ss, "ge") == 0) ? mas | 64 : mas;
		mas = (strcmp(ss, "gy") == 0) ? mas | 128 : mas;
		mas = (strcmp(ss, "da") == 0) ? mas | 192 : mas;
	}


	printf("%hhx\n", mas);

	return 0;
}