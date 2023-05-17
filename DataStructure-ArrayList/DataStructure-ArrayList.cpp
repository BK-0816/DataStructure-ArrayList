#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;


void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("Position error");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("List overflow");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

element remove(ArrayListType* L, int pos)
{
	element item;
	if (pos < 0 || pos >= L->size)
		error("Position error");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

int main()
{
	ArrayListType list;
	int choice, position, value;

	init(&list); 

	while (1) {
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the number: ");
			scanf_s("%d", &value);
			printf("Enter the position: ");
			scanf_s("%d", &position);
			insert(&list, position, value);
			printf("Move: %d\n", list.size - position);
			break;
		case 2:
			if (is_empty(&list))
				printf("List empty\n");
			break;
	
			printf("Enter the position: ");
			scanf_s("%d", &position);
			value = remove(&list, position);
			printf("Move: %d\n", list.size - position);
			
			break;
		case 3:
			print_list(&list);
			break;
		case 0:
			exit(0);
		default:
			printf("Invalid menu. Please select menu.\n");
		}
	}

	return 0;
}