#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[22],type[15];
	int qty,price;
	struct node* link;
};
struct node* root=NULL;


void list(struct node* n)
{
	int k=1;
	printf("\t\t\t--- ITEM LIST ---");
	printf("\n------+------------------+-------------------+----------+-------");
	printf("\n| No. | Name             | Type              | Quantity | Price |");
	printf("\n------+------------------+-------------------+----------+-------");
	if(n==NULL)
	{
		printf("\n------+------------------+-------------------+----------+-------");
	}
	else
	{
		printf("\n| %2d | %18s| %18s| %10d| $%4d",k,n->name,n->type,n->qty,n->price);
		k++;
		while(n->link!=NULL)
		{
			n=n->link;
			printf("\n| %2d | %18s| %18s| %10d| $%4d",k,n->name,n->type,n->qty,n->price);
			k++;
		}
		printf("\n------+------------------+-------------------+----------+-------");
		
	}
}


void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
		do
		{
			fflush(stdin);
			printf("Input Name of The New Item [3..20]: ");
			scanf("%[^\n]",temp->name);
		}
		while(strlen(temp->name) < 3 || strlen(temp->name) > 20);
		do
		{
			fflush(stdin);
			printf("\n Input Type of The New Item [processor/graphic card/memory]: ");
			scanf("%[^\n]",temp->type);
		}
		while(strcmp(temp->type,"processor") && strcmp(temp->type,"graphic card")  && strcmp(temp->type,"memory"));
		do
		{
			fflush(stdin);
			printf("\nInput Quantity of The New Item [1..20]: ");
			scanf("%d",&temp->qty);
		}
		while(temp->qty < 1 || temp->qty > 20);
		do
		{
			printf("\nInput Price of The New Item [$1..$1000]:$ ");
			scanf("%d",&temp->price);
		}
		while(temp->price < 1 || temp->price > 1000);
	if(root==NULL)
	{
		temp->link=NULL;
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;	
	}
}


void erase()
{
	char nama[20];
	struct node* p;
	p=(struct node*)malloc(sizeof(struct node));
	
	if(root==NULL)
	{
		printf("--- There are no item available ---");
	}
	else
	{
		p=root;
		root=root->link;
		printf("The recently added item <%s> is being delete.",p->name);
		free(p);
	}
}


void menu()
{
	int ch;
	system("cls");
	printf("COOL COMPUTER ADMINISTRATOR");
	printf("\n***************************");
	printf("\n\n1. Item List");
	printf("\n2. Add (PUSH) New Item");
	printf("\n3. Delete (POP) Recently Added Item");
	printf("\n4. Exit");
	printf("\n\n>> Input your choice : ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1 :
			system("cls");
			list(root);
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
			erase();
			getch();
			menu();
			break;
		case 4 :
			free(root);
			root=NULL;
			menu();
	}
}


void main()
{
	menu();
}
