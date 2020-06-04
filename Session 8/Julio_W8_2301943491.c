#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
	char name[20];
	int numb;
	struct node *left,*right;
};
struct node *root=NULL;
int k=0;

struct NameList
{
	char name[20];
	int numb;
}LIST[20];

void list()
{
	int x;
	printf("Player List :\n");
	for(x=0;x < k;x++)
	{
		printf("-%-10s <%2d>\n",LIST[x].name,LIST[x].numb);
	}
}

struct node *newnode(char *nama, int numb)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	struct node *ptr,*pptr;
	char pst[7];
	// if root is NULL
	if(root==NULL)
	{
		strcpy(temp->name,nama);
		temp->numb=numb;
		temp->left=temp->right=NULL;
		strcpy(LIST[k].name,nama);
		LIST[k].numb=numb;
		k++;
		printf("\n\n---Add Player Success---");
		return temp;
	}
	// if the root isn't NULL
	else
	{
		strcpy(temp->name,nama);
		temp->numb=numb;
		temp->left=temp->right=NULL;
		ptr=root;
		while(ptr!=NULL)
		{
			pptr=ptr;
			printf("Will He be in 'Left' or 'Right' %s: ",ptr->name);
			scanf("%s",pst);
			if(strcmp(pst,"Left")==0)
			{
				ptr=ptr->left;
			}
			if(strcmp(pst,"Right")==0)
			{
				ptr=ptr->right;
			}
		}
		// The last input of pst will be the position of newnode
		if(strcmp(pst,"Left")==0)
		{
			pptr->left=temp;
		}
		if(strcmp(pst,"Right")==0)
		{
			pptr->right=temp;
		}
	}
	strcpy(LIST[k].name,nama); // ordered list 
	LIST[k].numb=numb;
	k++;
	printf("\n\n---Add Player Success---");
}

void append()
{
	char tnama[25],position;
	int tnumb;
	do
	{
		fflush(stdin);
		printf("Input Player's Name [3..20]: ");
		scanf("%[^\n]",tnama);
	}while(strlen(tnama) < 3 || strlen(tnama) > 20);
	do
	{
		fflush(stdin);
		printf("Input Player's Back Number [1..99]: ");
		scanf("%d",&tnumb);
	}while(tnumb < 1 || tnumb > 99);
	if(root==NULL)
		root=newnode(tnama,tnumb); // add data to root	
	else  
	{
		newnode(tnama,tnumb);// newnode will linked to root
	}
}

void inorder(struct node *test){
    if(test != NULL)
	{
        inorder(test->left);
        printf("<%d>\n", test->numb);
        inorder(test->right);
    }
}

void preorder(struct node *test){
    if(test != NULL)
	{
        printf("<%d>\n", test->numb);
        preorder(test->left);
        preorder(test->right);
    }
}

void postorder(struct node *test){
    if(test != NULL)
	{
        postorder(test->left);
        postorder(test->right);
        printf("<%d>\n", test->numb);
    }
}
void menu()
{
	int ch;
	system("cls");
	printf("BLUE FOOTBALL MANAGER");
	printf("\n--------------------");
	printf("\n\n1. View All Player");
	printf("\n2. Add Player");
	printf("\n3. Preorder, Inorder, Postorder");
	printf("\n4. Exit and Remove all");
	printf("\n\n>> Input Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :
			system("cls");
			list();
			getch();
			menu();
		case 2 :
			system("cls");
			append();
			getch();
			menu();
		case 3 :
			system("cls");
			printf("Preorder:\n");
			preorder(root);
			printf("\nInorder:\n");
			inorder(root);
			printf("\nPostorder:\n ");
			postorder(root);
			getch();
			menu();
		case 4 :
			free(root);
			exit (0);
	}
}

main()
{
	menu();
}
