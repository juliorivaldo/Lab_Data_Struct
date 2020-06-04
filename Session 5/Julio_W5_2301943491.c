#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int qty,price;
	char name[30];
	struct node* link;
};
struct node* root=NULL, *tail=NULL, *test;
int k;

void list()
{
	struct node* test;
	k=1;
	printf("\t\t--- Order List ---\n");
	printf("-+-----+--------------------------------+----------+------------+-\n");
	printf(" | No. | Name of Parts                  | Quantity | Unit Price | \n");
	printf("-+-----+--------------------------------+----------+------------+-\n");
	if(root==NULL)
		printf("-- EMPTY --\n");
	else
	{
		test=root;
		do
		{
			printf(" | %3d | %-30s | %8d | %10d |\n",k++,root->name,root->qty,root->price);
			root=root->link;
		}while(root!=test);
	}
	printf("-+-----+--------------------------------+----------+------------+-\n");
}

void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	do
	{
		fflush(stdin);
		printf("Input Name of Motorcycle's Part [3..30]: ");
		scanf("%[^\n]",temp->name);
	}while(strlen(temp->name) < 3 || strlen(temp->name) > 30);
	do
	{
		fflush(stdin);
		printf("\nInput Quantity of The Motorcycle's Part[1..20]: ");
		scanf("%d",&temp->qty);
	}while(temp->qty < 1 || temp->qty > 20 );
	printf("\nInput Price of The Motorcycle's Part : ");
	scanf("%d",&temp->price);
	if(root==NULL)
	{
		root=tail=temp;
	}
	else
	{
		tail->link=temp;
		tail=temp;
	}
	tail->link=root;
	
	
	// check circular
//	printf("\n%d",tail->link);
//	printf("\n%d",root);
}


void annulbeg()
{
	struct node* temp;
	temp=root;
	if(temp->link==temp)
	{
		root=0;
	}
	else
	{
		tail->link=temp->link;
	}
	free(temp);
}


void annul()
{
	struct node *nextnode, *curr;
	int x=1,no;
	
	curr=root;
	list();
	if(root==NULL)
	{
		printf("\n\n--There is ni Data--");
	}
	else 
	{
		do
		{
		printf("\n\nInput Number of The Order [1..%d]: ",k-1);
		scanf("%d",&no);
		}while(no < 1 ||no > k-1 );
		if(no==1)
			annulbeg();
		else 
		{
			while(x < no-1)
			{
				curr=curr->link;
				x++;
			}
			nextnode=curr->link;
			curr->link=nextnode->link;
			free(nextnode);
		}
	}
}


void menu()
{
	int ch;
	system("cls");
	printf("BLUE MOTOR PARTS");
	printf("\n*****************");
	printf("\n1. View Order List");
	printf("\n2. Add New Order");
	printf("\n3. Take Order");
	printf("\n4. Exit");
	printf("\n\n>> Input Choice: ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1 :
			system("cls");
			list();
			getch();
			menu();
			break;
		case 2 :
			system("cls");
			append();
			getch();
			menu();
			break;
		case 3 :
			system("cls");
			annul();
			getch();
			menu();
			break;
		case 4 :
			exit(0);
	}
}


void main()
{
	menu();
}
