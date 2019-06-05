#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int data;
} Node;

Node* head = NULL;
Node* tail = NULL;

void init_node();
void insert_node_first(int data);
void insert_node_last(int data);
void remove_node_first();
void remove_node_last();
void remove_node_all();
void destructor();
void view_data_all();

int main()
{
	init_node();
	//insert_node_first(10);
	//insert_node_first(20);
	/*insert_node_last(60);
	insert_node_first(20);
	insert_node_last(70);
	insert_node_last(80);*/

	view_data_all();
	printf("\n");

	remove_node_first();
	view_data_all();
	remove_node_all();

	destructor();
}

void init_node()
{
	head = malloc(sizeof(Node));
	if (head != NULL)
	{
		head->next = tail;
		printf("create head and tail\n");
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
	Node* newNode = malloc(sizeof(Node));
	Node* target = head;
	while (target->next != tail)
	{
		target = target->next;
	}

	if (newNode != NULL)
	{
		target->next = newNode;
		newNode->next = tail;
		newNode->data = data;
	}
}

void remove_node_first()
{
	Node* target = head->next;
	if (target != tail)
	{
		head->next = target->next;
		free(target);
	}
	else
	{
		printf("지울게 없음\n");
	}
}

void remove_node_last()
{
	Node* target = head;
	Node* temp = NULL;
	while (target->next != tail)
	{
		temp = target;
		target = target->next;
	}

	if (temp != NULL)
	{
		temp->next = tail;
		free(target);
	}
	else
	{
		printf("지울게 없음\n");
	}

}

void remove_node_all()
{
	while (head->next != tail)
	{
		Node* target = head->next;
		head->next = target->next;
		printf("destroy target %d\n", target->data);
		free(target);
	}
}

void destructor()
{
	remove_node_all();

	printf("destroy head and tail\n");
	free(head);
	free(tail);
}

void view_data_all()
{
	Node* target = head->next;
	while (target != tail)
	{
		printf("target : %d\n", target->data);
		target = target->next;
	}
}



























































































































