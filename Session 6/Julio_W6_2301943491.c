#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[30],ads[50],cty[30];
	int phone;
	struct node *next, *prev;
};
struct node *root=NULL,*tail=NULL,*test;


void list()
{
	int k=1;
	test=root;
	printf("\t\t--- DATABASE CUSTOMER ---\n\n");
	printf("-+------+--------------------------+--------------------+---------------+---------------+-\n");
	printf(" | No.  | Company Name             | Address            | City          | Phone Number  |\n");
	printf("-+------+--------------------------+--------------------+---------------+---------------+-\n");
	if(root==NULL)
		printf("--- EMPTY ---\n");
	else
	{
		do
		{
			printf(" |%-3d. | %30s | %20s | %12s | %15d |\n",k++,test->name,test->ads,test->cty,test->phone);
			test=test->next;
		}while(test!=NULL);
	}
	printf("-+------+--------------------------+--------------------+---------------+---------------+-\n");
}


void view()
{
	printf("\t\t--- ORDER LIST ---\n\n");
	printf("-+------+------------------------------+----------+------------+-\n");
	printf(" | No.  | Name of Parts                | Quantity | Unit Price |\n");
	printf("-+------+------------------------------+----------+------------+-\n");
	printf(" | 1.   | Tank cover                   |        3 |   450000   |\n");
	printf(" | 2.   | Disk Brake                   |        2 |   900000   |\n");
	printf(" | 3.   | Head lamp                    |        4 |   800000   |\n");
	printf(" | 4.   | Spion                        |        3 |   300000   |\n");
	printf("-+------+------------------------------+----------+------------+-\n");
}


void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	list();
	do
	{
		fflush(stdin);
		printf("\n\nInput Company name[5..30]: ");
		scanf("%[^\n]",temp->name);
	}while(strlen(temp->name) < 5 || strlen(temp->name) > 30);
	do
	{
		fflush(stdin);
		printf("\nInput address[5..30]: ");
		scanf("%[^\n]", temp->ads);
	}while(strlen(temp->ads) < 5 || strlen(temp->ads) > 30);
	do
	{
		fflush(stdin);
		printf("\nInput City[5..20]: ");
		scanf("%[^\n]: ",temp->cty);
	}while(strlen(temp->cty) < 5 || strlen(temp->cty) > 30);
	do
	{
		fflush(stdin);
		printf("\nInput Phone Number[8..10]");
		scanf("%d",&temp->phone);
	}while(temp->phone < 8);
	if(root==NULL)
	{
		root=tail=temp;
		root->next=NULL;
		root->prev=NULL;
	}
	else
	{
		while(tail->next !=NULL)
		{
			tail=tail->next;
		}
		tail->next=temp;
		temp->prev=tail;
		temp->next=NULL;
		tail=temp;
	}
}


void menu()
{
	int ch;
	system("cls");
	printf("DATABASE CUSTOMER");
	printf("\n*********************");
	printf("\n\n1. View Customer Database");
	printf("\n2. Add New Customer");
	printf("\n3. Exit");
	printf("\n\n>> Input Choice: ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1 :
			system("cls");
			view();
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
			exit(0);
	}
}

void main()
{
	menu();
}
