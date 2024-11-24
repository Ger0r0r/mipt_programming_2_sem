#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Stack {
	int n;
	int size;
	Data * a;
};

struct Stack * stack_create(int size);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
int stack_is_empty(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);

int main ()
{

	struct Stack * sp = stack_create(10);

	int a, b;
	char y[2];

	while(scanf("%s", y) != EOF)
	{
		switch (y[0])
		{
			case '=':
				printf("%i\n", stack_pop(sp));
				stack_destroy(sp);
				return 0;
				break;
			case '8':
			case '9':
			case '7':
			case '6':
			case '5':
			case '4':
			case '3':
			case '2':
			case '1':
			case '0':
				stack_push(sp, atoi(y));
				break;
			case '-':
				a = stack_pop(sp);
				b = stack_pop(sp);
				stack_push(sp, b - a);
				break;
			case '+':
				stack_push(sp, stack_pop(sp) + stack_pop(sp));
				break;
			case '*':
				stack_push(sp, stack_pop(sp) * stack_pop(sp));
				break;
			default:
			;
		}
	}

	printf("%i\n", stack_pop(sp));

	stack_destroy(sp);
	
	return 0;
}

struct Stack * stack_create(int size)
{
	struct Stack *t = (struct Stack * )calloc(1, (sizeof(struct Stack)));
	t->a = calloc(size, sizeof(Data));
	t->size = size;
	return t;
}

void stack_push(struct Stack * s, Data x)
{
	if (s->n >= s->size)
	{
		(s->size) *= 2;
		s->a = realloc(s->a, (s->size) * sizeof(Data));
	}
	
	s->a[s->n] = x;
	++(s->n);
}

Data stack_pop(struct Stack * s)
{
	--s->n;
	Data x = s->a[s->n];
	s->a[s->n] = 0;
	return x;
}

Data stack_get(struct Stack * s)
{
	return s->a[s->n];
}

int stack_is_empty(struct Stack * s)
{
	if (s->n == 0)
		return 1;
	else
		return 0;
}

void stack_print(struct Stack * s)
{
	if (s->n == 0)
	{
		printf("Empty stack\n");
	}
	else
	{
		for (int i = 0; i < s->n; ++i)
		{
			printf("%i ", s->a[i]);
		}
		printf("\n");
	}
}

int stack_size(struct Stack * s)
{
	return s->n;
}

void stack_clear(struct Stack * s)
{
	for (int i = 0; i < s->size; ++i)
	{
		s->a[i] = 0;
	}
	s->n = 0;
}

void stack_destroy(struct Stack * s)
{
	free(s->a);
	free(s);
}