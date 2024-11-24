#include <stdio.h>

#define N 100
typedef int Data;


struct Stack {
	int n;
	Data a[N];
};

void stack_create(struct Stack * s);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
void stack_clear(struct Stack * s);

int main ()
{
	Data x = 0;
	struct Stack s;

	stack_create(&s);

	stack_push(&s, 5);
	stack_print(&s);//ppp

	stack_push(&s, 19);
	stack_print(&s);//ppp

	x = stack_size(&s);
	printf("size=%d\n", x);//ppp

	x = stack_pop(&s);	
	printf("x=%d\n", x);//ppp

	stack_print(&s);//ppp

	x = stack_pop(&s);
	printf("x=%d\n", x);//ppp

	stack_print(&s);//ppp

	return 0;
}

void stack_create(struct Stack * s)
{
	for (int i = 0; i < 100; ++i)
	{
		s->a[i] = 0;
	}
	s->n = 0;
}

void stack_push(struct Stack * s, Data x)
{
	s->a[s->n] = x;
	++s->n;
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
	for (int i = 0; i < 100; ++i)
	{
		s->a[i] = 0;
	}
	s->n = 0;
}