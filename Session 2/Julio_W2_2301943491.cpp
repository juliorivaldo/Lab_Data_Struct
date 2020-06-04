#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nodes=0;

struct node 
{
	char genre[7];
	int data;
	struct node* link;
};
struct node* root=NULL;


void display(struct node* n)
{
	if(n==NULL)
	{
		break;
	}
	else
	{
		printf(" \n  [ %5s CD           |   %2d song<s> ] -> [top]\n", n->genre, n->data);
		while(n->link != NULL)
		{
			n=n->link;
			printf("  [ %5s CD           |   %2d song<s> ] ", n->genre, n->data);
			printf("\n");
		}
		printf("\n");
	}
}


void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	
	if(nodes > 9)
	{
		printf("--- The CD Storage is Full ---");
	}
	else
	{
		do
		{
			printf("Input CD Genre [rock/jazz/blues] : ");
			scanf("%s",temp->genre);
		}
		while(strcmp(temp->genre,"rock")!=0 && strcmp(temp->genre, "jazz")!=0 && strcmp(temp->genre, "blues")!=0);
		do
		{
			printf("\n Input the number of songs on the CD [5...12] : ");
			scanf("%d",&temp->data);
		}
		while(temp->data < 5 || temp->data > 12);
		if(root==NULL)
		{
			temp->link=NULL;
			root = temp;
			nodes++;
		}
		else
		{
			temp->link = root;
			root=temp;
			nodes++;
		}
	}
}

void erase()
{
	struct node* p;
	p=(struct node*)malloc(sizeof(struct node));
	
	if(root==NULL)
	{
		printf("--- The CD Storage is empty ---");
	}
	else
	{
		p=root;
		root=root->link;
		free(p);
		nodes--;
		printf("--- Sell CD Success ---");
	}
}

void menu()
{
	int ch;
	system("cls");
	printf("JACKIE CD STOCK\n");
	printf("-------------------");
	printf("\nCD STOCK <stack>");
	display(root);
	printf("\n\nOption :");
	printf("\n1. Stock of CD");
	printf("\n2. Sell a CD");
	printf("\n3. Exit");
	printf("\n\n>> Input Choice : ");
	scanf("%d",&ch);
	switch (ch)
		{
			case 1 :
				system("cls");
				append();
				menu();
			case 2 :
				system("cls");
				erase();
				menu();
			default :
				return;
		}
}

main()
{
	menu();
	
}
