// C program to implement bus management sysyem //
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Structure
typedef struct node {
	char name[20]; 
	char gen[6]; // gender type//
	int age; // age of passenger //
	struct node* link;
} Node;
Node* start = NULL;

void heading();
void add_node(char[10],char[6],int);
void details();
void travel();
void nepal();
void inter();
void receipt();

int k, amount;
char about[60], to_reach[30], date[20];

int main()
{
	system("color f0");
	printf("Welcome to the travel management by bus ");
	printf("This is captain Sudip Dhakal");
	int a;
	heading();
	printf("\t\t\t\t1. International " // Taking Choice From User
		"Tour Packages\n\t\t\t\t2.Nepal tour packages\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	
	switch(a) {
	case 1:
		inter();
		break;
	case 2:
		nepal();
		break;
	default:
		printf("Enter Right Choice...");
		break;
	}

	details();
	receipt();
}

void nepal()
{
	int a;
	system("cls");
	heading();
	
	strcpy(about, "Nepal Tour");
	printf("\t\t\t\t1. Muktinath Tour Packages "
		"6 Days 7 Nights (18880/-)\n");
	printf("\t\t\t\t2. Illam Tour Packages "
		"5 Days 4 Nights (5000/-)\n");
	printf("\t\t\t\t3.  Lumbini Tour Packages "
		"11 Days 10 Nights (5000/-)\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	if (a == 1) {
		strcpy(to_reach, "Muktinath Tour");
		amount = 18880;
	}
	else if (a == 2) {
		strcpy(to_reach, "Illam Tour");
		amount = 5000;
	}
	else if (a == 3) {
		strcpy(to_reach, "Lumbini Tour");
		amount = 5000;
	}
	else
		printf("Enter Correct Choice...");
}

	void inter() // choice for international tour //
{
	int a;
	system("cls");
	heading();
	
	strcpy(about, "International Tour Package");
	printf("\t\t\t\t1. India Tour Packages "
		"6 Days 7 Nights (28880/-)\n");
	printf("\t\t\t\t2. Thailand Tour Packages "
		"5 Days 4 Nights (15500/-)\n");
	printf("\t\t\t\t3. UK Tour Packages "
		"11 Days 10 Nights (567800/-)\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	if (a == 1) {
		strcpy(to_reach, "India Tour");
		amount = 28880;
	}
	else if (a == 2) {
		strcpy(to_reach, "Thailand Tour");
		amount = 15500;
	}
	else if (a == 3) {
		strcpy(to_reach, "UK Tour");
		amount = 567800;
	}
	else
		printf("Enter Correct Choice...");
}

void details()
{
	int i, a;
	char val[20], gen[6];
	system("cls");

	heading();
	printf("\t\t\t\tEnter Number Of Passengers: ");
	scanf("%d", &k);
	printf("\t\t\t\tEnter Date (DD/MM/YY): ");
	fflush(stdin);
	gets(date);
	for (i = 1; i <= k; i++) {
		system("cls");
		heading();
		printf("\t\t\t\tEnter The %dth Passenger Name: ",i); 
		gets(val);
		printf("\t\t\t\tEnter The %dth Passenger Gender: ",i);
		fflush(stdin);
		gets(gen);
		printf("\t\t\t\tEnter The %dth passener age ",i);
		fflush(stdin);
		scanf("%d", &a);
		
		add_node(val, gen, a);
	}
}

void add_node(char hh[20],  //Function to add details in node for each passengers
			char der[6], int b)
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, hh);
	strcpy(newptr->gen, der);
	newptr->age = b;
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}

void receipt() // Function For Printing Receipt
{
	int i, b;
	Node* ptr = start;
	system("cls");
	heading();
	printf("\n\t\t\t\t**Take Screenshot "
		"For Further Use**\n");
	for (i = 1; i <= k; i++) {
		printf("\t\t\t\t%dst Passenger name : ",i);
		puts(ptr->name);
		printf("\t\t\t\t%dst Passenger gender ",i);
		puts(ptr->gen);
		printf("\t\t\t\t%dst Passenger age: %d\n\n",i, ptr->age);	
		ptr = ptr->link;
	}
	printf("\t\t\t\tSelected Type: ");
	puts(about);
	printf("\t\t\t\tPackage: ");
	puts(to_reach);
	printf("\t\t\t\tDate: ");
	puts(date);
	b = amount * k;
	printf("\t\t\t\tTotal Amount: %d", b);
	printf("\n\t\t\t\t**Thank You For "
		"registration**");
}

void heading()
{
	printf("\t\t***Tourism Package Management System***\n");
	printf("\t\t***Vaccination certificate is necessary for travel purpose***\n\n");
}

