/*
Written by : Julio Rivaldo Gunawan
NIM : 2301943491
Topic : Circular Dobly Linked List
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[15],order[25],add[50];
	struct node *next,*prev;
};
struct node *root=NULL,*tail=NULL,*test;
int x=1;

void list()
{
	int ch,k;
	do{
	system("cls");
	printf("1. Ascending");
	printf("\n2. Descending");
	printf("\n\n>> Number: ");
	scanf("%d",&ch);
	system("cls");
	}while(ch > 2);
	if(ch==1)
	{
		printf("\n\n--- ACE FOOD DELIVERY ORDER LIST ---\n");
		printf("-+-----+---------------+------------------+-------------------------+-\n");
		printf(" | No. | Customer Name |     Food Order   |     Delivery Address    |\n");
		printf("-+-----+---------------+------------------+-------------------------+-\n");
		if(root==NULL)
			printf("--- EMPTY ---\n");
		else
		{
			k=1;
			test=root;
			do
			{
				printf(" |%4d |%-14s |%-17s |%-25s|\n",k++,test->name,test->order,test->add);
				test=test->next;
			}while(test!=root);
		}
	}
	else
	{
		printf("\n\n--- ACE FOOD DELIVERY ORDER LIST ---\n");
		printf("-+-----+---------------+------------------+-------------------------+-\n");
		printf(" | No. | Customer Name |     Food Order   |     Delivery Address    |\n");
		printf("-+-----+---------------+------------------+-------------------------+-\n");
		if(root==NULL)
			printf("--- EMPTY ---\n");
		else
		{
			k=x-1;
			test=tail;
			do
			{
				printf(" |%4d |%-14s |%-17s |%-25s|\n",k--,test->name,test->order,test->add);
				test=test->prev;
			}while(test!=tail);
		}
	}
	printf("-+-----+---------------+------------------+-------------------------+-\n");
}

void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	do
	{
		fflush(stdin);
		printf("Input Customer Name [3..30]: ");
		scanf("%[^\n]",temp->name);
	}while(strlen(temp->name) < 3 || strlen(temp->name) > 30);
	do
	{
		fflush(stdin);
		printf("Input Food Order[3..20]: ");
		scanf("%[^\n]",temp->order);
	}while(strlen(temp->order) < 3 || strlen(temp->order) > 20);
	do
	{
		fflush(stdin);
		printf("Input Delivery Address[6..30]: ");
		scanf("%[^\n]",temp->add);
	}while(strlen(temp->add) < 6 || strlen(temp->add) > 30);
	if(root==NULL)
	{
		root=tail=temp;
		root->next=tail;
		root->prev=tail;
	}
	else
	{
		if(root==tail)
			x=2; // number for descending part
			
		while(tail->next!=root) // search the last node
		{
			tail=tail->next;
		}
		tail->next=temp;
		temp->prev=tail;
		temp->next=root;
		root->prev=temp;
		tail=temp;
		x++;
	}
}

void erase()
{
	struct node *pptr, *ptr;
	int a=1,b,k ;
	printf("\n\n--- ACE FOOD DELIVERY ORDER LIST ---\n");
	printf("-+-----+---------------+------------------+-------------------------+-\n");
	printf(" | No. | Customer Name |     Food Order   |     Delivery Address    |\n");		
	printf("-+-----+---------------+------------------+-------------------------+-\n");
	if(root==NULL)
		printf("--- EMPTY ---\n");
	else
	{
		k=1;
		test=root;
		do
		{
			printf(" |%4d |%-14s |%-17s |%-25s|\n",k++,test->name,test->order,test->add);
			test=test->next;
		}while(test!=root);
	}
	printf("-+-----+---------------+------------------+-------------------------+-\n");
	printf("\n\nInput Number of The Order [1..%d]: ",x-1);
	scanf("%d",&b);
	test=root;
	if(b==1)
	{
		root=root->next;test->next=NULL;
		root->prev=tail;test->prev=NULL;
		tail->next=root;
		free(test);
	}
	else
	{
		while(a!=b)
		{
			test=test->next;
			a++;
		}
		pptr=test->prev;ptr=test->next;
		pptr->next=test->next;ptr->prev=test->prev;
		test->next=test->prev=NULL;
		free(test);
		x=x-1;
	}
}

void menu()
{
	int ch;
	system("cls");
	printf("ACE FOOD DELIVERY");
	printf("\n-----------------");
	printf("\n\n1. View Order list");
	printf("\n2. Add New Order");
	printf("\n3. Take Order");
	printf("\n4. Exit");
	printf("\n\n>> Input Choice: ");
	scanf("%d",&ch);
	switch(ch)
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
			erase();
			getch();
			menu();
			break;
		case 4 :
			free(root);
			exit(0);
	}
}


void main()
{
	menu();
}
