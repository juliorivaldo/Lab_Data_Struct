#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_node 10
struct node
{
	int numb;
	struct node *next;
};

struct graphs
{
	struct node* adj;
};

void CreateGraph(int size)
{
	int i;
	struct graphs *Graph[size];
	for(i = 0 ; i < size ; i++)
	{
		Graph[i]= malloc( sizeof(struct node*));
		Graph[i]->adj=NULL;
	}
	return Graph[size];
}

struct node *createNode(int v)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->numb=v;
	newNode->next=NULL;
	return newNode;
}

void addEdge (struct graphs *Graph[], int s, int d)
{
	struct node *dest, *tmp, *src;
	//request location to make a node
	if(Graph[s]->adj==NULL)
	{
		src=(struct node*)malloc(sizeof(struct node));
		src->numb=s;
		src->next=NULL;
		Graph[s]->adj = src;
	}
	dest = (struct node*)malloc(sizeof(struct node));
	dest->numb = d;
	dest->next = NULL;
	tmp = Graph[s]->adj;
	//search the last node 
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next=dest;
}

void show_List(struct graphs *Graph[],int vert_size)
{
	int v,k=0;
	for(v=0 ; v < vert_size; v++)
	{
		struct node *temp=Graph[v]->adj;
		while(temp !=NULL)
		{
			printf("%d ->",temp->numb);
			temp=temp->next;
		}
		printf("\n");
	}
}

void show_adj()
{
	int vert_size,i,j;
	char ans;
	struct graphs *Graph[max_node];
	do
	{
		printf("\n\nHow Many Vertices ? <max=10> : ");
		scanf("%d",&vert_size);
	}while(vert_size < 1 || vert_size > 10);
	CreateGraph(vert_size);
	for(i=1 ; i <= vert_size ; i++)
	{
		for(j=1 ; j <= vert_size ; j++)
		{
			if(i !=j)
			{
				fflush(stdin);
				printf("Vertices %d & %d are Adjacent ? <y/n> : ",i,j);
				scanf("%c",&ans);
				if(ans=='y')
					addEdge(Graph,i,j);
			}
		}
	}
	//show_matrix(Graph)
	show_List(Graph,vert_size);
}

void menu()
{
	int ch;
	system("cls");
	printf("Directed Graph Representation\n");
	printf("=============================\n");
	printf("\n1. Show Adjacency Matrix");
	printf("\n2. Show Adjacency List");
	printf("\n3. Show Degree of all Vertices");
	printf("\n4. Exit");
	printf("\n\n>> Input Choice: ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1 :
			show_adj();
			getch();
			menu();
			system("cls");
	}
}

main()
{
	menu();
}
