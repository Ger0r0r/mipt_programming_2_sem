#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned short adr;
typedef unsigned short word;

byte b_read(adr a);			
void b_write(adr a, byte val);  
word w_read(adr a);			
void w_write(adr a, word val);
void load_file();
void mem_dump(adr start, word n);

union Direct{
	byte b[65536];
	word w[32768];
};

union Direct mem;

byte b_read  (adr a)
{
	return mem.b[a];
}  

void b_write (adr a, byte val)
{
	mem.b[a] = val;
}

word w_read  (adr a)
{
	return mem.w[a / 2];
}

void w_write (adr a, word val)
{
	mem.w[a / 2] = val;
}

void load_file()
{
	adr a = 0;
	unsigned int n = 0;
	byte rem = 0;
	
	scanf("%hx%x", &a, &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%hhx", &rem);
		b_write(a, rem);
		a++;
	}
}

void mem_dump(adr start, word n)
{
	word rem = 0;
	
	for (word i = 0; i < n; i += 2)
	{
		rem = w_read(start);
		printf("%06o : %06o\n", start, rem);
		start += 2;
	}
}
