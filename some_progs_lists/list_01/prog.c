#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};
typedef struct Node * List;

List list_create ();
void list_push (List * plist, Data x);
Data list_pop (List * plist);
void list_clear(List * plist);
Data list_get(List list);
void list_print (List list);
int list_size(List list);
int list_is_empty(List list);

int main ()
{
	List a = list_create();
	int aa = list_size(a);
	printf("%d\n", aa);
	list_push(&a,6);
	list_push(&a,7);
	printf("%d\n", list_size(a));
	list_print(a);
	printf("%d\n", (int)list_pop(&a));
	list_push(&a,4);
	list_print(a);
	list_clear(&a);
	if (list_is_empty(a))
	{
		list_print(a);
	}
}

List list_create ()
{
	return NULL;
}

void list_push (List * plist, Data x)
{
	struct Node * tt = calloc(1,sizeof(struct Node));
	tt->val = x;
	tt->next = plist[0];
	plist[0] = tt;
}

Data list_pop (List * plist)
{
	Data px = plist[0]->val;
	struct Node * tt;
	tt = plist[0];
	plist[0] = plist[0]->next;
	tt->next = NULL;
	free(tt);
	return px;
}

void list_clear(List * plist)
{
	struct Node * tt;
	while(plist[0])
	{
		tt = plist[0];
		plist[0] = plist[0]->next;
		tt->next = NULL;
		free(tt);
	}
}

Data list_get(List list)
{
	return list->val;
}

void list_print (List list)
{	
	if (!list)
	{
		printf("Empty list\n");
	}
	else
	{
		while(&list[0])
		{
			printf("%lli ", (long long int)list[0].val);
			list = list[0].next;
		}
		printf("\n");
	}
}

int list_size(List list)
{
	int capacity = 0;
	while(&list[0])
	{
		capacity++;
		list = list[0].next;
	}
	return capacity;
}

int list_is_empty(List list)
{
	if (list == NULL)
		return 1;
	return 0;
}