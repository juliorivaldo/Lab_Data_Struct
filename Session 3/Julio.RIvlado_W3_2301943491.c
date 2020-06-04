#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[15], brand[7], type[25], dmg[50];
	struct node* link;
};
struct node *root = NULL, *ptr, *pptr;



void list(struct node* n)
{
	int k=1;
	if (n==NULL)
	{
		printf("+------+---------------------+------------------+------------+------------------------+\n");
		printf("| No.  | Customer Name       | Printer's Brand  | Type       | Damaged                |");
		printf("\n+------+---------------------+------------------+------------+------------------------+\n");
	}
	else
	{
		printf("+------+---------------------+------------------+------------------------+------------------+\n");
		printf("| No.  | Customer Name       | Printer's Brand  | Type                   | Damaged        |");
		printf("\n+------+---------------------+------------------+----------------------+-------------------+\n");
		printf("| %-2d.  | %-18s  | %-15s  | %-20s   | %-15s|",k,n->name,n->brand,n->type,n->dmg);
		k++;
		while(n->link!=NULL)
		{
			n=n->link;
			printf("\n| %-2d.  | %-18s  | %-15s  | %-20s   | %-15s|",k,n->name,n->brand,n->type,n->dmg);
			k++;
		}
		printf("\n+------+---------------------+------------------+----------------------+-------------------+\n");
	}
	
}

void append()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Input Customers Name: ");
	scanf("%s",temp->name);
		do
		{
			printf("\nInput Printer's Brand [canon/epson/hp]: ");
			scanf("%s",temp->brand);
		}
		while(strcmp(temp->brand,"canon") && strcmp(temp->brand,"epson") && strcmp(temp->brand,"hp"));
		do
		{
			fflush(stdin);
			printf("\nInput Printer's Type [4..20]: ");
			scanf("%[^\n]",temp->type);
		}
		while(strlen(temp->type) < 4 || strlen(temp->type) > 20);
		do
		{
			fflush(stdin);
			printf("\nInput Damaged [5..100]: ");
			scanf("%[^\n]",temp->dmg);
		}
		while(strlen(temp->dmg) < 5 || strlen(temp->dmg) > 100);
		if(root==NULL)
		{
			temp->link=NULL;
			root=temp;
		}
		else
		{
			struct node* p;
			p=root;
			temp->link=NULL;
			while(p->link !=NULL)
			{
				p = p->link;
			}
			p->link=temp;
		}
	
}

void erase()
{
	int x=1,no;
	ptr=pptr=root;
    if(root==NULL)
    {
        printf("\n --- The CD Storage is Empty ---\n");
        return;
    }
    else
    {
    	struct node *temp;
        printf(">> di delet setelah nomer : ");
        scanf("%d",&no);
        
        while(x!=no);
        {
        	pptr=pptr->link;
        	x++;
		}
		ptr=pptr->link;
		pptr->link=ptr->link;
		ptr->link=NULL;
		root->link=ptr;
		free(pptr);
		
		printf("masuk");
		getch();		
    }
}

void menu()
{
	int a;
	system("cls");
	printf("PRINTER SERVICES");
	printf("\n++++++++++++++++++++");
	printf("\n\n1. Service List");
	printf("\n2. Add Service");
	printf("\n3. Take Service");
	printf("\n4. Exit");
	printf("\n\n>> Input Your Choice : ");
	scanf("%d",&a);
	switch (a)
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
			menu();
			break;
		case 3 :
			system("cls");
			erase();
			menu();
			break;
		default :
			printf("\n End Of Run");
			exit(0);
	}
}

void main()
{
	menu();
}
