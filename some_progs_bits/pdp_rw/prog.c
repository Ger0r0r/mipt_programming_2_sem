#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned short adr;
typedef unsigned short word;

byte b_read  (adr a);			
void b_write (adr a, byte val);  
word w_read  (adr a);			
void w_write (adr a, word val);  

union Direct{
	byte b[65536];
	word w[32768];
};

union Direct mem;

byte b_read  (adr a)
{
	/*printf("Щас будет СУЕТА\n");
	for (int i = 0; i < 65536; ++i)
	{
		printf("%s\n", );
	}*/



	//printf("Функция b_read\n");
	//printf("Вошло adr a = %hu\n", a);
	//printf("Вышло mem[a] = %hhu\n", mem.b[mem.w[a]]);
	//printf("\n");
	return mem.b[a];
}  

void b_write (adr a, byte val)
{
	//printf("Функция b_write\n");
	//printf("Вошло adr a = %hu byte val = %hhu\n", a, val);
	mem.b[a] = val;
	//printf("\n");
}

word w_read  (adr a)
{
	//printf("Функция w_read\n");
	//printf("Вошло a = %hu\n", a);
	//printf("Вышло mem[a] = %hu\n", mem.w[mem.w[a]]);
	//printf("\n");
	return mem.w[a / 2];
}

void w_write (adr a, word val)
{
	//printf("Функция w_write\n");
	//printf("Вошло adr a = %hu word val = %hu\n", a, val);
	mem.w[a /2] = val;
	//printf("\n");
}


// 0000000000000000111111111111111100000010000000011111111111111111000000000000000000000000000000000000000000000000
// ________--------________--------________--------________--------________--------________--------________--------
// 0	   1	   2	   3	   4	   5	   6	   7