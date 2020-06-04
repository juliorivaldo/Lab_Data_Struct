#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct cake {
	char no[3],code[7],name[35];
	int avail,price;
};
struct cake arr_cake[] = {
								{"01","CK001","Blueberry Cake",13,25000},
								{"02","CK009","Chocochip Cake",5,20000},
								{"03","CK017","Mayonaise Cake",24,30000},
								{"04","CK023","Strawberry ShortCake",7,17500}
						  };

void tampilan(){
	int i=0;
	printf("BLUE CAKE SHOP CASHIER\n");
	printf("==========================\n\n");
	printf("No. | Cake Code | Cake Name         | Available | Price \n");
	printf("---------------------------------------------------------------\n");
	while(i<4){
		printf("%-2s | %-7s | %-20s | %-9d | Rp. %7d,- \n",arr_cake[i].no,arr_cake[i].code,arr_cake[i].name,arr_cake[i].avail,arr_cake[i].price);
		i++;	
	}
}

void sell(){
	int i,jumlah,k=0,total=0,bayar,kembalian;
	char temp[7];
	system("cls");
	tampilan();
	printf("\n\nInput Cake Code [5 chars]: ");
	scanf("%s",temp);
	for(i=0;i<4;i++){
		if(strcmp(temp,arr_cake[i].code)==0){
			k=i;
			printf("\nInput Quantity [0..%d]: ",arr_cake[i].avail);
			scanf("%d",&jumlah);
				if (jumlah<arr_cake[i].avail){
				total=arr_cake[i].price*jumlah;
				printf("\nTotal Price is : Rp %d,- x %d = Rp %d,-",arr_cake[i].price,jumlah,total);
				printf("\nPembayaran : Rp ");
				scanf("%d",&bayar);
				kembalian=bayar - total;
					if (kembalian>=0){
						arr_cake[i].avail=arr_cake[i].avail-jumlah;
						printf("\nKembalian anda = Rp %d,-",kembalian);
						printf("\n--THANKYOU--");
						getch();
					}
					else printf("\nUang anda kurang");
			}
				else printf("\n...The Quantity of cake is not enough...");
			getch();
		}
		}
	if (strcmp(temp,arr_cake[k].code)!=0){
		printf("\n--- The Cake Code doesn't Exist---");
		getch();
}
}

void tambah(){
	int banyak,i,k=0;
	char temp[7];
	system("cls");
	tampilan();
	printf("\n\nInput Cake Code [5 chars]: ");
	scanf("%s",temp);
	for(i=0;i<4;i++){
		if(strcmp(temp,arr_cake[i].code)==0){
			k=i;
		do{
			printf("\nInput Quantity [1..10]: ");
			scanf("%d",&banyak);
		}
		while (banyak<0 || banyak>10);
		printf("\n--Adding Stock Success--");
		arr_cake[i].avail=arr_cake[i].avail+banyak;
		getch();
		}
	}
	if (strcmp(temp,arr_cake[k].code)!=0){
		printf("\n--- The Cake Code doesn't Exist---");
		getch();
	}
}


void menu(){
		int a;
		system("cls");
		tampilan();
		printf("Menu :\n1. Sell\n2. Add Stock\n3. Exit\n");
		printf("Input Choice : ");
		scanf("%d",&a);
		switch (a){
			case 1 :
				sell();
				menu();
				break;
			case 2 :
				tambah();
				menu();
				break;
		}
}

main(){
	menu();
}
