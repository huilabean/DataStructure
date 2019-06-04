#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int data;
} Node;

Node* head;


void init_node()
{
	head = malloc(sizeof(Node));
	if (head != NULL)
	{
		head->next = NULL;
		head->data = 0;
	}
	else
	{
		// Memory was not allocated.
	}
}

void insert_node_first(int data)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->next = head->next;
		head->next = newNode;
		newNode->data = data;
	}
	else
	{
		// Memory was not allocated.
	}
}

void insert_node_last(int data)
{
	Node* currentNode = head->next;
	Node* newNode;

	if (currentNode == NULL)
	{
		newNode = malloc(sizeof(Node));
		if (newNode != NULL)
		{
			currentNode = newNode;
			currentNode->next = NULL;
			currentNode->data = data;
		}
		else
		{
			// Memory was not allocated.
		}
	}
	else
	{
		while (currentNode != NULL)
		{
			currentNode = currentNode->next;
		}

		newNode = malloc(sizeof(Node));
		if (newNode != NULL)
		{
			currentNode = newNode;
			newNode->next = NULL;
			newNode->data = data;
		}
		else
		{
			// Memory was not allocated.
		}
	}
}

void destroy_node()
{
	Node* target;
	while (head->next != NULL)
	{
		target = head->next;
		head->next = target->next;
		printf("destroy node data: %d\n", target->data);
		free(target);
	}

	free(head);
	printf("destroy node head\n");
}

int main(void)
{
	Node* current;
	init_node();

	insert_node_first(10);
	insert_node_last(20);

	current = head->next;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}

	destroy_node();


	return 0;
}






















































































