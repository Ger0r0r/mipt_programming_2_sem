#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};

struct Node * list_create ();
struct Node * list_push (struct Node * list, Data x);
struct Node * list_pop (struct Node * list, Data * px);
struct Node * list_clear(struct Node * list);
Data list_get(struct Node * list);
void list_print (struct Node * list);
int list_size(struct Node * list);
int list_is_empty(struct Node * list);

int main ()
{
	Data x;
	struct Node * list = list_create();
	printf("%i\n", list_is_empty(list));
	list = list_push(list, 5);
	list = list_push(list, 2);
	list = list_push(list, 19);
	list_print(list);
	list = list_pop(list, &x);
	printf("x = %d\n", x);
	printf("%i\n", list_is_empty(list));
	list = list_clear(list); 
	return 0;
}

struct Node * list_create ()
{
	return NULL;
}

struct Node * list_push (struct Node * list, Data x)
{
	struct Node * tt = calloc(1,sizeof(struct Node));
	tt->val = x;
	tt->next = list;
	return tt;
}

struct Node * list_pop (struct Node * list, Data * px)
{
	*px = list[0].val;
	struct Node * tt;
	tt = list[0].next;
	free(list);
	return tt;
}

struct Node * list_clear(struct Node * list)
{
	struct Node * tt;
	while(list)
	{
		tt = list->next;
		free(list);
		list = tt;
	}
	return NULL;
}

Data list_get(struct Node * list)
{
	return list->val;
}

void list_print (struct Node * list)
{
	while(&list[0])
	{
		printf("%lli ", (long long int)list[0].val);
		list = list[0].next;
	}
	printf("\n");
}

int list_size(struct Node * list)
{
	int capacity = 0;
	while(&list[0])
	{
		capacity++;
		list = list[0].next;
	}
	return capacity;
}

int list_is_empty(struct Node * list)
{
	if (list == NULL)
		return 1;
	return 0;
}