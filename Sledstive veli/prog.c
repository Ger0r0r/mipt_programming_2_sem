#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef char color;

const int L = 40;//Длина плана
const int H = 10;//Высота плана

typedef struct Sl{
	int size;
	color CC;
	int *pat;
}Sled;

void printPlan(char *pp);
color paintSection(char *pp, int n);
void repaintPlan(char *pp, color a, color b);
int paintPlan(char *pp);
void minPlan(char *pp, int cc);
void PerfectPaint(char *pp);

int main (int argc, char ** argv)
{
	FILE * txt, * res;

	if (argc < 1)
	{
		printf("Enter file.tex after start program");
		exit(-1);
	}
	
	res = fopen ("result.txt", "w");
	txt = fopen (argv[1], "r");

	if( errno )
	{
		perror("input.dat не удалось открыть\n");
		exit(1);
	}

	char* plan = calloc(H * L + 2, sizeof(char));

	char* ss = calloc(L + 2, sizeof(char));

	for(int i = 0; i < H; ++i)
	{
		bzero(ss, (L + 2) * sizeof(char));

		fgets(ss, L, txt);

		int len = strlen(ss);

		for (int k = 0; k < len; ++k)
		{
			if (ss[k] == '\n')
				ss[k] = ' ';
		}

		for (int i = 0; i < L - len; ++i)
		{
			ss[L - i - 1] = ' ';
		}

		strcat(plan, ss);
	}
	printPlan(plan);

	printf("\nNow Im going to paint\n\n");

	int nColor = paintPlan(plan);

	printf("\nI already painted plan!\n\n");

	printPlan(plan);

	minPlan(plan, nColor);

	printf("\nI already painted plan!\n\n");
	
	printPlan(plan);

	color t[L+2];

	memset(t, 0, L+2);
	
	t[L]='\n';

	for (int i = 0; i < H; i++)
	{
		memcpy(t, &plan[i*L], L+1);
		fprintf(res, "%s", t);
		fputc('\n', res);

	}
	
	/*for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < L; j++)
		{
			fputc(plan[i * L + j], res);
		}
		
		fputc('\n', res);

	}*/

	fclose(res);
	fclose(txt);
	free(plan);
	free(ss);
	return 0;
}

void printPlan(char *pp)
{
	printf("--------------------------------------------------\n");
	for (int i = 0; i < H; ++i)
	{
		for (int l = 0; l < L; ++l)
		{
			printf("%c", pp[i * 40 + l]);
		}
		printf("\n");
	}
	printf("--------------------------------------------------\n");
}

color printSection(char *pp, int n)
{
	color a = 0;
	if ((n + L + 1 >= 0)	&& (n + L + 1 < H * L) 	&& (pp[n + L + 1] != ' ') 	&& (pp[n + L + 1] != '+')) 
	{	
		if (a == 0)	
			a = pp[n + L + 1];
		else
			repaintPlan(pp, a, pp[n + L + 1]);
	}
	if ((n + L >= 0) 		&& (n + L < H * L) 		&& (pp[n + L] != ' ') 		&& (pp[n + L] != '+') 	 ) 
	{	
		if (a == 0)	
			a = pp[n + L];
		else
			repaintPlan(pp, a, pp[n + L]);
	}
	if ((n + L - 1 >= 0) 	&& (n + L - 1 < H * L) 	&& (pp[n + L - 1] != ' ') 	&& (pp[n + L - 1] != '+')) 
	{	
		if (a == 0)	
			a = pp[n + L - 1];
		else
			repaintPlan(pp, a, pp[n + L - 1]);
	}
	if ((n + 1 >= 0) 		&& (n + 1 < H * L) 		&& (pp[n + 1] != ' ') 		&& (pp[n + 1] != '+') 	 ) 
	{	
		if (a == 0)	
			a = pp[n + 1];
		else
			repaintPlan(pp, a, pp[n + 1]);
	}
	if ((n - 1 >= 0) 		&& (n - 1 < H * L) 		&& (pp[n - 1] != ' ') 		&& (pp[n - 1] != '+') 	 ) 
	{	
		if (a == 0)	
			a = pp[n - 1];
		else
			repaintPlan(pp, a, pp[n - 1]);
	}
	if ((n - L + 1 >= 0) 	&& (n - L + 1 < H * L) 	&& (pp[n - L + 1] != ' ') 	&& (pp[n - L + 1] != '+')) 
	{	
		if (a == 0)	
			a = pp[n - L + 1];
		else
			repaintPlan(pp, a, pp[n - L + 1]);
	}
	if ((n - L >= 0) 		&& (n - L < H * L) 		&& (pp[n - L] != ' ') 		&& (pp[n - L] != '+') 	 ) 
	{	
		if (a == 0)	
			a = pp[n - L];
		else
			repaintPlan(pp, a, pp[n - L]);
	}
	if ((n - L - 1 >= 0) 	&& (n - L - 1 < H * L) 	&& (pp[n - L - 1] != ' ') 	&& (pp[n - L - 1] != '+')) 
	{	
		if (a == 0)	
			a = pp[n - L - 1];
		else
			repaintPlan(pp, a, pp[n - L - 1]);
	}
	return a;
}

void repaintPlan(char *pp, color a, color b)
{
	//printf("==================================================\n");

	//printPlan(pp);

	//printf("MAGIC\n");

	for (int i = 0; i < H*L; ++i)
		if (pp[i] == b)
			pp[i] = a;
			
	//printPlan(pp);

	//printf("==================================================\n");
}

int paintPlan(char *pp)
{
	color t = 'A';
	color r = 0;
	for (int i = 0; i < H*L; ++i)
	{
		if (pp[i] == '+')
		{
			pp[i] = printSection(pp, i);
			if (pp[i] == 0)
			{
				pp[i] = t + r;
				++r;
			}
		}

	}
	return r;
}

void minPlan(char *pp, int cc)
{
	Sled *Mas = calloc(cc, sizeof(Sled));

	int *Cul = calloc(cc, sizeof(int));

	for (int j = 0; j < H*L; ++j)
		if (pp[j] != ' ') 
		{
			//printf("%c\n", pp[j]);
			++Cul[pp[j] - 'A'];
		}

	int rcc = cc;
	
	for (int i = 0; i < cc; ++i)
	{
		//printf("Cul[%i] = %i\n", i, Cul[i]);
		Mas[i].size = Cul[i];
		Mas[i].CC = 'A' + i;
		//printf("%i %c\n", Mas[i].CC, Mas[i].CC);
		Mas[i].pat = calloc(Mas[i].size, sizeof(int));
	}

	for (int j = 0; j < H*L; ++j)
		if (pp[j] != ' ') 
			for (int i = 0; i < cc; i++)
			{
				//printf("%i %i\n", Mas[i].CC, pp[j]);
				if (Mas[i].CC == pp[j])
				{
					//printf("j = %i i = %i p = %i m.c = %i m.s = %i\n", j, i, pp[j], Mas[i].CC, Mas[i].size);
					Mas[i].pat[Mas[i].size - Cul[i]] = j;
					--Cul[i];
				}
				
			}
			
	//==================================================

	int dd = 0;
	char f = 1;
	for (int i = 0; i < cc; i++) 
	{
		if (Mas[i].size == 0)
		{
			--rcc;
		}
		else
			for (int j = 0; j < i; j++)
			{
				f = 1;
				if (Mas[i].size == Mas[j].size)
				{
					if (Mas[i].size == 1)
					{
						repaintPlan(pp, Mas[j].CC, Mas[i].CC);
						Mas[i].CC = Mas[j].CC;
						--rcc;
						break;
					}
					else
					{
						dd = Mas[i].pat[0] - Mas[j].pat[0];
						for (int k = 0; k < Mas[i].size; k++)
						{
							if (dd != Mas[i].pat[k] - Mas[j].pat[k])
								f = 0;
						}
						if (f == 1)
						{
							repaintPlan(pp, Mas[j].CC, Mas[i].CC);
							Mas[i].CC = Mas[j].CC;
							--rcc;
							break;
						}
						
					}
				}
					
			}
	}

	//==================================================

	printPlan(pp);

	//printf("\naaaaa\n");

	for (int i = 0; i < cc; ++i)
	{
		printf("%i\t %c\t", Mas[i].size, Mas[i].CC);
		for (int j = 0; j < Mas[i].size; j++)
			printf("%i ", Mas[i].pat[j]);
		printf("\n");
		
		free(Mas[i].pat);
	}

	printf("%i", rcc);

	PerfectPaint(pp);

	free(Cul);
	free(Mas);
}

void PerfectPaint(char *pp)
{
	color maxS = 'A';
	for (int i = 0; i < H*L; ++i)
	{
		if (pp[i] > maxS)
		{
			++maxS;
			repaintPlan(pp, maxS, pp[i]);
		}
		
	}
}