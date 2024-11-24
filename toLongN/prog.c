#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
// a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
	int n; 			// размер числа в разрядах
	char sign;		// знак числа
	char dig[0];	// массив для хранения "цифр" числа (одна точно есть):
}LongN;

LongN *  getLongN(char * s);
LongN * copyLN(const LongN *b);
void showDigit(const LongN *a);
void destroyLN(LongN * a);
LongN * invertLN(const LongN *a, int n);
LongN * sumLN(const LongN *a, const LongN *b);
LongN * div2LN(const LongN *a);
LongN * MultLN( const LongN * a, const LongN * b);

int main ()
{
	char st[201];

	scanf("%s", st);

	LongN *a = getLongN(st);

	scanf("%s", st);

	LongN *b = getLongN(st);

	LongN *s = div2LN(a);
	showDigit(s);
	destroyLN(s);

	s = MultLN(a,b);
	showDigit(s);
	destroyLN(s);

	destroyLN(a);
	destroyLN(b);

	return 0 ;
}

//==================================================//

LongN *  getLongN(char * s)
{
	LongN *tmp = calloc(1, (sizeof (LongN) + 100 * sizeof(char)));

	char eSi = 0;

	if (s[0] == '-')
	{
		tmp->sign = 1;
		eSi = 1;
	}
	else if (s[0] == '+')
	{
		tmp->sign = 0;
		eSi = 1;
	}
	else tmp->sign = 0;

	char lenstr = strlen(s) - eSi;

	tmp->n = (lenstr + 1) / 2;

	char a[3];
	a[2] = '\0';

	if (lenstr % 2 == 0)
	for (int i = 0; i < tmp->n; ++i)
	{
		a[0] = s[2*i + eSi];
		a[1] = s[2*i + eSi + 1];
		tmp->dig[tmp->n - 1 - i] = atoi(a);
	}
	else
	{
		a[0] = s[eSi];
		a[1] = '\0';
		tmp->dig[tmp->n - 1] = atoi(a);
		for (int i = 1; i < tmp->n; ++i)
		{
			a[0] = s[2*i + eSi - 1];
			a[1] = s[2*i + eSi];
			tmp->dig[tmp->n - 1 - i] = atoi(a);
		}
	}

	//showDigit(tmp);

	return tmp;
}

//==================================================//

LongN * copyLN(const LongN *b)
{
	LongN *tmp = calloc(1, (sizeof (LongN) + 100 * sizeof(char)));

	tmp->n = b->n;
	tmp->sign = b->sign;

	for (int i = 0; i < b->n; ++i)
	{
		tmp->dig[i] = b->dig[i];
	}

	return tmp;
}

//==================================================//

void showDigit(const LongN *a)
{
	if (a->sign == 1) 	printf("- ");
	else 				printf("+ ");

	for (int i = a->n - 1; i >= 0; --i)
	{
		if (a->dig[i] == 0 && i != 0) {
			printf("00 ");
		} else {
			printf("%i ", a->dig[i]);
		}
	}

	printf("\n");
}

//==================================================//

void destroyLN(LongN * a)
{
	free(a);
}

//==================================================//

LongN * invertLN(const LongN *a, int n)
{
	LongN *tmp = calloc(1, (sizeof (LongN) + 101 * sizeof(char)));

	tmp->n = n;
	tmp->sign = a->sign;

	tmp->dig[0] = 100 - a->dig[0];

	for (int i = 1; i < n; ++i)
		{
			tmp->dig[i] = 99 - a->dig[i];
		}

	return tmp;

}

//==================================================//

LongN * sumLN(const LongN *a, const LongN *b)
{
	int Mn = (a->n >= b->n) ? a->n : b->n;
	int ol = 0;

	LongN *tmp = calloc(1, (sizeof (LongN) + 101 * sizeof(char)));

	LongN *moa = copyLN(a);
	LongN *mob = copyLN(b);

	if (a->sign == b->sign)
	{
		tmp->sign = a->sign;

		for (int i = 0; i < Mn + 1; ++i)
		{
			ol = moa->dig[i] + mob->dig[i] + ol / 100;
			tmp->dig[i] = ol % 100;
		}

		if (ol % 100 >= 1) ++Mn;

	}
	else
	{
		if (a->sign == 1)
		{
			destroyLN(moa);
			moa = invertLN(a,Mn);
		}
		else
		{
			destroyLN(mob);
			mob = invertLN(b,Mn);
		}

		for (int i = 0; i < Mn; ++i)
		{
			ol = moa->dig[i] + mob->dig[i] + ol / 100;
			tmp->dig[i] = ol % 100;
		}

		tmp->sign = (moa->sign + mob->sign + ol / 100) % 2;

		destroyLN(moa);
		destroyLN(mob);

		tmp->n = Mn;

		LongN *tmp2;

		if (tmp->sign == 0)
			tmp2 = copyLN(tmp);
		else
			tmp2 = invertLN(tmp, Mn);

		destroyLN(tmp);

		while (tmp2->dig[Mn - 1] == 0)
		{
			if (Mn == 1)
			break;
			--Mn;
		}

		tmp2->n = Mn;

		return tmp2;
	}

	tmp->n = Mn;

	destroyLN(moa);
	destroyLN(mob);

	return tmp;
}

//==================================================//

LongN * div2LN(const LongN *a)
{
	LongN *t = calloc(1, (sizeof (LongN) + 101 * sizeof(char)));

	t->sign = a->sign;

	int ol = 0;

	for (int i = a->n - 1; i >= 0; --i)
	{
		t->dig[i] = (100 * ol + a->dig[i]) / 2;
		ol = a->dig[i] % 2;
	}

	if (a->n > 1)
	{
		if (t->dig[a->n - 1] == 0) t->n = a->n - 1;
		else t->n = a->n;
	}
	else t->n = a->n;

	return t;
}

//==================================================//

LongN * MultLN( const LongN * a, const LongN * b)
{
	LongN *t = calloc(1, (sizeof (LongN) + 101 * sizeof(char)));

	int ol = 0;

	LongN *o;
	LongN *p = calloc(1, (sizeof (LongN) + 101 * sizeof(char)));

	for (int i = 0; i < a->n+1; ++i)
	{

		o = calloc(1, (sizeof (LongN) + 101 * sizeof(char)));

		o->n = b->n + i + 1;

		for (int j = 0; j < b->n+1; ++j)
		{
			o->dig[i+j] = (a->dig[i] * b->dig[j] + ol) % 100;
			ol = (a->dig[i] * b->dig[j] + ol) / 100;
		}
		ol = 0;

		free(t);
		t = sumLN(o,p);
		free(o);
		free(p);

		p = copyLN(t);
	}

	t->sign = (a->sign + b->sign) % 2;

	int Mn = a->n * b->n + 1;

	while (t->dig[Mn - 1] == 0)
		{
			if (Mn == 1)
			break;
			--Mn;
		}

	t->n = Mn;

	return t;
}