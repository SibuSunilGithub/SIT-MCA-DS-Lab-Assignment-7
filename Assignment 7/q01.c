// Double Linked List Implimentation Program...
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
	struct node *prev;
};
struct node *start = NULL;

// Function Initializations
void create();
void display();
void display_reverse();
int count_node();
void insert_first(int ele);
void insert_last(int ele);
void insert_after_node(int ele, int key);
void insert_before_node(int ele, int key);
// Main Functions
int main()
{
	printf("\nDouble Linked List Operations\n");
	printf("Create A Double Linked List\n");
	create();
	display();
	display_reverse();
	count_node();

	// Menu Driven Options
	int choice, ele, key, pos;
	while (1)
	{
		printf("\n0 - Exit The Program");
		printf("\n1 - Insert First");
		printf("\n2 - Insert Last");
		printf("\n3 - Insert After A Given Node");
		printf("\n4 - Insert Before A Given Node"); /*
		 printf("\n5 - Insert At A Specific Position");
		 printf("\n6 - Delete First");
		 printf("\n7 - Delete Last");
		 printf("\n8 - Delete After A Given Node");
		 printf("\n9 - Delete Before A Given Node");
		 printf("\n10 - Delete At A Specifc Position");
		 printf("\n11 - Delete Any Node With A Given Key\n");*/

		printf("\nEnter Your Option:");
		scanf("%d", &choice);

		// Switch - Case Section
		switch (choice)
		{
		case 1:
			printf("\nEnter The Element To Insert At First: ");
			scanf("%d", &ele);
			insert_first(ele);
			display();
			break;
		case 2:
			printf("\nEnter The Element To Insert At Last: ");
			scanf("%d", &ele);
			insert_last(ele);
			display();
			break;
		case 3:
			printf("\nEnter The Node: ");
			scanf("%d", &key);
			printf("\nEnter The Element To Insert After Node %d : ", key);
			scanf("%d", &ele);
			insert_after_node(key, ele);
			display();
			break;
		case 4:
			printf("\nEnter The Node: ");
			scanf("%d", &key);
			printf("\nEnter The Element To Insert Before Node %d : ", key);
			scanf("%d", &ele);
			insert_before_node(key, ele);
			display();
			break; /*
		 case 5:
			 printf("\nEnter The Position: ");
			 scanf("%d", &pos);
			 printf("\nEnter The Element To Insert At Position %d : ", pos);
			 scanf("%d", &ele);
			 insert_specific_position(pos, ele);
			 display();
			 break;
		 case 6:
			 delete_first();
			 display();
			 break;
		 case 7:*/

		case 0:
			printf("Program Exit Successfully.\n");
			exit(0);

			printf("\n");
		}
	}
}
// -  Create DLL
void create()
{
	struct node *new, *curr;
	char check;
	do
	{
		new = (struct node *)malloc(sizeof(struct node));
		printf("Enter Element: ");
		scanf("%d", &new->info);
		new->next = NULL;

		if (start == NULL)
		{
			start = new;
			new->prev = NULL;
			curr = new;
		}
		else
		{
			new->prev = curr;
			curr->next = new;
			curr = new;
		}
		printf("Enter Choice y To Continue: ");
		scanf(" %c", &check);
	} while (check == 'y');
}

// -  Display Or Traverse Function
void display()
{
	struct node *temp;
	temp = start;
	if (temp == NULL)
	{
		printf("List Is Empty!\n");
		return;
	}
	printf("List Is: ");
	while (temp)
	{
		printf("%d ", temp->info);
		temp = temp->next;
	}
}

// - Display In Reverse Order
void display_reverse()
{
	struct node *temp;
	temp = start;
	if (temp == NULL)
	{
		printf("List Is Empty!\n");
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	printf("List Is: ");
	while (temp != NULL)
	{
		printf("%d ", temp->info);
		temp = temp->prev;
	}
}

// - Count No Of Nodes In DLL
int count_node()
{
	struct node *temp;
	temp = start;
	if (start == NULL)
	{
		printf("\nNode Is Empty!\n");
		return;
	}
	int count = 0;
	while (temp->next)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// - Insert First In DLL
void insert_first(int ele)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Can't Be Created!\n");
		exit(0);
	}
	new->info = ele;
	new->prev = NULL;
	new->next = start;
	start->prev = new;
	start = new;
}

// - Insert Last In DLL
void insert_last(int ele)
{
	struct node *new;
	struct node *temp;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Can't Be Created!\n");
		exit(0);
	}
	new->info = ele;
	new->next = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	new->prev = temp;
	temp->next = new;
}

//  - Insert After A Given Node
void insert_after_node(int key, int ele)
{
	struct node *new;
	struct node *temp;
	temp = start;
	while ((temp != NULL) && (temp->info != key))
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("\nKey Is Not Present!\n");
		return;
	}

	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Can't Be Created!\n");
		exit(0);
	}
	new->info = ele;
	new->next = temp->next;
	temp->next->prev = new;
	new->prev = temp;
	temp->next = new;
}

//  - Insert Before A Given Node
void insert_before_node(int key, int ele)
{
	struct node *new;
	struct node *temp;

	temp = start;
	while ((temp != NULL) && (temp->next->info != key))
	{
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		printf("\nKey Is Not Present!\n");
		return;
	}

	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL)
	{
		printf("\nMemory Allocation Fails!\n");
		exit(0);
	}
	new->info = ele;
	if (temp == start)
	{
		new->next = start;
		start = new;
	}
	else
	{
		new->next = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}
