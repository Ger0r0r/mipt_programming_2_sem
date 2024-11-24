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
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
int  stack_is_empty(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);

int main()
{
	Data x = 0;
	struct Stack * sp = stack_create(3);
	stack_push(sp, 5);
	stack_push(sp, 19);
	stack_push(sp, -2);
	stack_print(sp);
	// 5 19 -2

	stack_push(sp, 27);
	stack_print(sp);
	// 5 19 -2 27
	printf("is_empty=%d\n", stack_is_empty(sp));
	// is_empty=0

	x = stack_pop(sp);
	printf("x=%d\n", x);
	// x=27

	x = stack_pop(sp);
	printf("x=%d\n", x);
	// x=-2

	stack_print(sp);
	// 5 19

	while (!stack_is_empty(sp)) {
		stack_pop(sp);
		stack_print(sp);
	}
	// 5
	// Empty stack

	stack_destroy(sp);
}

struct Stack* stack_create(int size)
{
	struct Stack *s = (struct Stack *)calloc(1, sizeof(struct Stack));
	s->a = calloc(size, sizeof(Data));
	s->size = size;
	stack_clear(s);
	return s;
}

void stack_push(struct Stack * s, Data x)
{
	if (s->n >= s->size)
	{
		(s->size) *= 2;
		s->a = realloc(s->a, (s->size) * sizeof(Data));
	}
		s->a[s->n] = x;
		(s->n)++;
}

Data stack_pop(struct Stack * s)
{
	(s->n)--;
	Data rem = s->a[s->n];
	s->a[s->n] = 0;
	return rem;
}

Data stack_get(struct Stack * s)
{
	return s->a[s->n];
}

void stack_print(struct Stack * s)
{
	if (s->n == 0)
		printf("Empty stack\n");
	else
	{
		for (int i = 0; i < s->n; i++)
			printf("%d ", s->a[i]);
		printf("\n");
	}
}

int  stack_size(struct Stack * s)
{
	return s->n;
}

int  stack_is_empty(struct Stack * s)
{
	if (s->n == 0)
		return 1;
	return 0;
}

void stack_clear(struct Stack * s)
{
	for (int i = 0; i < s->n; i++)
		s->a[i] = 0;
	s->n = 0;
}

void stack_destroy(struct Stack * s)
{
	free(s->a);
	free(s);
}
