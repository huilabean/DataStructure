#include <stdio.h>
#include <stdlib.h>

// 구조체 선언. (클래스처럼 사용하기 위한 list 구조체)
typedef struct node
{
	struct node* prev;
	struct node* next;
	int data;
} Node;

Node* head = NULL;
Node* tail = NULL;

void initialization();
void destructor();
Node* begin(); // 리스트의 처음을 반환
Node* end(); // 리스트의 마지막을 반환
int isEmpty(); // 리스트가 비어있는지
int size(); // 리스트의 갯수
void push_back(int data);
void push_front(int data);
int pop_back();
int pop_front();
void clear(); // 리스트의 모든 원소를 제거한다.
void view_all();

int main()
{
	Node* target = NULL;

	initialization();
	push_back(10);
	push_back(20);
	push_front(5);
	push_back(30);
	push_front(0);

	pop_back();
	push_back(40);
	pop_front();

	view_all();
	destructor();
}

void initialization()
{
	head = malloc(sizeof(Node));
	tail = malloc(sizeof(Node));

	if (head != NULL && tail != NULL)
	{
		// head
		head->prev = NULL;
		head->next = tail;
		// tail
		tail->prev = head;
		tail->next = NULL;
		printf("Create Head and Tail\n");
	}
	else
	{
		// Memory was not allocated
	}
}

void destructor()
{
	free(head);
	free(tail);

	printf("Destroy Head and Tail\n");
}

Node* begin()
{
	Node* target = NULL;
	if (isEmpty())
	{
		printf("empty list\n");
		target = NULL;
	}
	else
	{
		target = head->next;
	}

	return target;
}

Node* end()
{
	Node* target = NULL;
	if (isEmpty())
	{
		printf("empty list\n");
		target = NULL;
	}
	else
	{
		target = tail->prev;
	}

	return target;
}

int isEmpty()
{
	int flag = 0;
	if (head->next == tail)
	{
		flag = 1;
	}

	return flag;
}

int size()
{
	int count = 0;
	Node* target = NULL;

	if (isEmpty())
	{
		count = 0;
	}
	else
	{
		target = head->next;
		while (target != tail)
		{
			target = target->next;
			count++;
		}
	}

	return count;
}

void push_back(int data)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->next = tail;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		tail->prev = newNode;
		newNode->data = data;
	}
	else
	{
		// Memory was not allocated.
	}
}

void push_front(int data)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->prev = head;
		newNode->next = head->next;
		head->next->prev = newNode;
		head->next = newNode;
		newNode->data = data;
	}
	else
	{
		// Memory was not allocated.
	}
}

int pop_back()
{
	int data = 0;
	Node* target = NULL;
	if (isEmpty())
	{
		printf("empty list\n");
		return 0;
	}
	else
	{
		target = tail->prev;
		tail->prev->next = tail;
		tail->prev = target->prev;
		data = target->data;
		free(target);
	}

	return data;
}

int pop_front()
{
	int data = 0;
	Node* target = NULL;
	if (isEmpty())
	{
		printf("empty list\n");
		return 0;
	}
	else
	{
		target = head->next;
		head->next = target->next;
		target->next->prev = head;
		data = target->data;
		free(target);
	}

	return data;
}

void clear()
{
	while (head->next != tail)
	{
		Node* target = head->next;
		head->next = target->next;
		printf("destroy target %d\n", target->data);
		free(target);
	}
}

void view_all()
{
	Node* target = head->next;
	while (target != tail)
	{
		printf("target : %d\n", target->data);
		target = target->next;
	}
}
