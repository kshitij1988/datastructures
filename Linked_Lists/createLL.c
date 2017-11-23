#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}ND;

int printll(ND *current)
{
	while(current != NULL)
	{
		printf("value of the node is %d\n" ,current->data);
		current = current->next;
	}
	return 0;
}

int main()
{
	ND *head=NULL,*second=NULL,*third=NULL;

	head = malloc(sizeof(ND));
	second = malloc(sizeof(ND));
	third = malloc(sizeof(ND));

	head->data = 23;
	head->next = second;

	second->data = 51;
	second->next = third;

	third->data = 111;
	third->next = NULL;

	printll(head);

	return 0;
}
