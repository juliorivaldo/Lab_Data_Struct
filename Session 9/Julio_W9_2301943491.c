#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int arr,price;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node *newnode(int code, int prc)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->arr=code;
	temp->price=prc;
	temp->left=temp->right=NULL;
	if(root==NULL)
		root=temp;
	return temp;
}

struct node *insert(struct node *node, int codes, int prcs)
{
	if(node==NULL) return newnode(codes,prcs);
	
	if(codes < node->arr)
		node->left=insert(node->left,codes,prcs);
	else if (codes > node->arr)
		node->right=insert(node->right,codes,prcs);
}

void append()
{
	int tcode,tprc;
	struct node *pptr;
	pptr=root;
	do
	{
		printf("Input Phone Code N[1-9][0-9][0-9][0-9]:N");
		scanf("%d",&tcode);
	}while(tcode < 1000 || tcode > 9999);
	do
	{
		printf("Input Phone Price[$50..$999]: ");
		scanf("%d",&tprc);
	}while(tprc < 50 || tprc > 999);
	if(root==NULL)
		root=insert(pptr,tcode,tprc);
	else
		insert(pptr,tcode,tprc);
}

struct node *search(struct node *ptr,int key)
{
	if(ptr==NULL)
		printf("---There is no Data in tree---");
	if(ptr->arr==key)
		return ptr;
	else if(ptr->arr < key) 
		return search(ptr->right,key);
		else
			return search(ptr->left,key);
}

void edit()
{
	struct node *data,*ptr;
	int temp,newprice;
	ptr=root;
	do
	{
		printf("Input Phone Code N[1-9][0-9][0-9][0-9]:N");
		scanf("%d",&temp);
	}while(temp < 1000 || temp > 9999);
	data=search(ptr, temp);
	printf("\n\nPhone Code  : N%-4d",data->arr);
	printf("\nPhone Price : $%-4d",data->price);
	printf("\n\nInput New Phone Price: $");
	scanf("%d",&newprice);
	data->price=newprice;
}

void preorder(struct node *test){
    if(test != NULL)
	{
        printf("- N%d [ $ %-3d]\n",test->arr,test->price);
        preorder(test->left);
        preorder(test->right);
    }
}

void inorder(struct node *test){
    if(test != NULL)
	{
        inorder(test->left);
        printf("- N%d [ $ %-3d]\n",test->arr,test->price);
        inorder(test->right);
    }
}

void postorder(struct node *test){
    if(test != NULL)
	{
        postorder(test->left);
        postorder(test->right);
        printf("- N%d [ $ %-3d]\n",test->arr,test->price);
    }
}

void menu()
{
	int ch,tcode,tprc;
	system("cls");
	printf("NOKIYEM CELLULAR PHONE\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%\n\n");
	printf("1. Add New Phone\n");
	printf("2. Update Phone Price\n");
	printf("3. Inorder, Preorder, Postorder\n");
	printf("4. Exit\n");
	printf("\n>> Input Your Choice: ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1 :
			system("cls");
			append();
			getch();
			menu();
			break;
		case 2 :
			system("cls");
			edit();
			getch();
			menu();
			break;
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
			break;
		case 4 :
			free(root);
			exit(0);
	}
}

main()
{
	menu();
}
