#include "stdio.h"
#include "stdlib.h"
typedef struct _Node
{
	void *value;
	struct _Node *next;
	struct _Node *prev;
} Node;

typedef struct _DoublyLinkedList
{
	size_t size;
	Node *head;
	Node *tail;
} DoublyLinkedList;

DoublyLinkedList* createDoublyLinkedList() {
	DoublyLinkedList *tmp = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}

void deleteDoublyLinkedList(DoublyLinkedList **list)
{
	Node *tmp = (*list)->head;
	Node *next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void pushFront(DoublyLinkedList *list, void *data)
{
	Node *tmp = (Node*) malloc(sizeof(Node));
	if (tmp == NULL)
	{
		exit(1);
	}
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
	{
		list->head->prev = tmp;
	}
	list->head = tmp;

	if (list->tail == NULL)
	{
		list->tail = tmp;
	}
	list->size++;
}

void *popFront(DoublyLinkedList *list)
{
	Node *prev;
	void *tmp;
	if (list->head == NULL)
	{
		exit(2);
	}

	prev = list->head;
	list->head = list->head->next;
	if (list->head)
	{
		list->head->prev = NULL;
	}

	if (prev == list->tail)
	{
		list->tail = NULL;
	}

	tmp = prev->value;
	free(prev);

	list->size--;
	return tmp;
}

void pushBack(DoublyLinkedList *list, void *value)
{
	Node *tmp = (Node*) malloc(sizeof(Node));
		if (tmp == NULL)
		{
			exit(3);
		}
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
	{
		list->tail->next = tmp;
	}
	list->tail = tmp;

	if (list->head == NULL)
	{
		list->head = tmp;
	}
	list->size++;
}

void* popBack(DoublyLinkedList *list)
{
	Node *next;
	void *tmp;
	if (list->tail == NULL)
	{
		exit(4);
	}

	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
	{
		list->tail->next = NULL;
	}
	if (next == list->head)
	{
		list->head = NULL;
	}
	tmp = next->value;
	free(next);

	list->size--;
	return tmp;
}

Node* getElem(DoublyLinkedList *list, size_t index)
{
	Node* tmp = list->head;
	size_t i = 0;
	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return tmp;
}

void insert(DoublyLinkedList *list, size_t index, void *value)
{
	Node *elm = NULL;
	Node *ins = NULL;
	elm = getElem(list, index);
	if (elm == NULL)
	{
		exit(5);
	}
	ins = (Node*)malloc(sizeof(Node));
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next)
	{
		elm->next->prev = ins;
	}
	elm->next = ins;

	if (!elm->prev)
	{
		list->head = elm;
	}

	if (!elm->next)
	{
		list->tail = elm;
	}

	list->size++;
}

void* deleteN(DoublyLinkedList *list, size_t index)
{
	Node *elm = NULL;
	void *tmp = NULL;
	elm = getElem(list, index);
	if (elm == NULL)
	{
		exit(5);
	}
	if (elm->prev)
	{
		elm->prev->next = elm->next;
	}
	if (elm->next)
	{
		elm->next->prev = elm->prev;
	}
	tmp = elm->value;

	if (!elm->prev)
	{
		list->head = elm->next;
	}
	if (!elm->next)
	{
		list->tail = elm->prev;
	}

	free(elm);
	list->size--;

	return tmp;
}

void printList(DoublyLinkedList *list, void (*fun)(void*))
{
	Node *tmp = list->head;
	while (tmp)
	{
		fun(tmp->value);
		printf(" ");
		tmp = tmp->next;
	}
	printf("\n");
}

void printInt(void *value)
{
	printf("%d", *((int*) value));
}

int main()
{
	DoublyLinkedList *list = createDoublyLinkedList();
	int a, b, c, d, e, f, g, h;

	a = 10;
	b = 20;
	c = 30;
	d = 55;

	pushFront(list, &d);
	pushBack(list, &a);
	pushFront(list, &c);
	printList(list, printInt);
	deleteN(list, 0);
	printList(list, printInt);
}
