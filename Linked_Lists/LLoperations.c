#include<stdio.h>
#include<stdlib.h>

#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#define DEBUG 0

typedef struct node{
	unsigned int data;
	struct node *next;
}ND;

int printll(ND *current)
{
	while(current != NULL)
	{
		printf("value of the node is %u\n" ,current->data);
		current = current->next;
	}
	return 0;
}

int createll(ND **head, int num)
{
	ND *current=NULL,*new=NULL;
	if(num == 0)
	{
		printf("No new element created\n");
	}
	else if(num == 1)
	{
		current = malloc(sizeof(ND));
		current->data = arc4random_uniform(100);
		current->next = NULL;
		printf("Single element added in the LL\n");
		(*head)=current;
		free(current);
	}
	else if(num >= 2)
	{
		new=current;
		current = malloc(sizeof(ND));
		current->data = arc4random_uniform(100);
		current->next = NULL;
		printf("Adding %d nodes in the LL\n" ,num);
		num--;
		while(num)
		{
			new = malloc(sizeof(ND));
			new->data = arc4random_uniform(100);
			new->next = current;
			current = new;
			num--;
		}
		(*head)=current;
		free(current);
	}
	else {
		printf("Enter a positive value\n");
	}
	return 0;
}

int addNodeBeginning(ND **head,int node)
{
	ND *current=malloc(sizeof(ND));
	current->data=node;
	if((*head) == NULL)
	{
		current->next=NULL;
	}
	else
	{
		current->next=(*head);
	}
	(*head)=current;
	return 0;
}

int addNodeEnd(ND **head,int node)
{
	ND *current=malloc(sizeof(ND)),*traverse=(*head);
	current->data=node;
	current->next=NULL;
	if((*head) == NULL)
		return 0;
	else
	{
		while(traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next=current;
		traverse=(*head);
		//(*head)=traverse;
		return 0;
	}
}

int addNodeSpecific(ND *head,int pos,int node)
{
	int i=0;
	ND *traverse=head,*current=NULL;
	if(head == NULL)
	{
		printf("Empty Linked List, Please try options 1,2 or 3\nThanks!\n");
		return 0;
	}
	while(i<(pos-1))
	{
		if(traverse == NULL)
		{
			printf("Position specified is beyond the length of Linked List\nPlease try again\n");
			return 0;
		}
		traverse = traverse->next;
		i++;
	}
	current=malloc(sizeof(ND));
	current->data=node;
	current->next=traverse->next->next;
	traverse->next=current;
	return 0;
}

int main()
{
	int option,nodenum,usernode,pos;
	char ans,warn;
	ND *main_head=NULL;

	printf("\n\n######## Welcome! to Linked List operation's program. ########\n\n");
	do{
		printf("Choose from existing options\n1. Create random LL\n2. Add a node at beginning\n3. Add a node at end\n4. Add a node at specific position\n5. Delete a node at beginning\n6. Delete a node at end\n7. Delete a node at specific position\n8. Print the Linked List\n");
		scanf("%d" ,&option);	

		switch(option){
			case 1 :
				if(main_head != NULL)
				{
					printf("You already have a Linked List do you want to discard it and form a new one? (y/n)\n");
					scanf(" %c", &warn);
					debug_print("DBGPRNT: value of warn is %c\n" ,warn);
					if(warn == 'N' || warn == 'n')
					{
						//debug_print("DBGPRNT: inside break\n");
						break;
					}
				}
				printf("Enter number of nodes you want to create\n");
				scanf("%d" ,&nodenum);
				createll(&main_head,nodenum);
				break;
			case 2 :
				printf("Enter the node you want to add at beginning\n");
				scanf("%d" ,&usernode);
				addNodeBeginning(&main_head,usernode);
				break;
			case 3 :
				printf("Enter the node you want to add at end\n");
				scanf("%d" ,&usernode);
				addNodeEnd(&main_head,usernode);
				break;
			case 4 :
				printf("Enter value of the node you want to add\n");
				scanf("%d" ,&usernode);
				printf("Enter the position of node you want to add\n");
				scanf("%d" ,&pos);
				addNodeSpecific(main_head,pos,usernode);
				break;
			case 5 :
				break;
			case 6 :
				break;
			case 7 :
				break;
			case 8 :
				printll(main_head);
				break;
			default :
				printf("Enter a valid option\n");
				break;
			}
		printf("Do you want to try another operation? (y/n)\n");
		scanf(" %c" ,&ans);
	}while(ans == 'Y' || ans == 'y');
	printf("\n######## GoodBye! Thanks ########\n"); 

	return 0;
}
