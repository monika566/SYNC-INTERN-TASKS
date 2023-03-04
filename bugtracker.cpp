
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void filebug(int id)
{
	printf("**********");
	printf("FILING A BUG");
	printf("***********\n");


	time_t CurrentTime;
	time(&CurrentTime);

	char name[20], bugtype[50];
	char bugdescription[1000];
	char bugpriority[30];
	int bugstatus;

	FILE* ptr;

	printf("Enter your name:\n");
	scanf("%s", name);
	char ids[10];
	itoa(id, ids, 10);
	strcat(name, ids);
	char ex[] = ".txt";
	strcat(name, ex);

	printf("Filename :%s\n", name);
	ptr = fopen(name, "w");

	if (ptr == NULL)
		printf("cannot create file!!!\n");

	fprintf(ptr, "DATE AND TIME : %s",
			ctime(&CurrentTime));

	fprintf(ptr, "BUG ID : %d\n", id);

	fprintf(ptr, "\n");

	
	printf("BUG ID:%d\n", id);

	fprintf(ptr, "BUG FILED BY: %s\n",
			name);
	fprintf(ptr, "\n");

	printf("Enter bug type:\n");
	scanf(" %[^\n]", bugtype);

	fprintf(ptr, "TYPE OF BUG: %s",
			bugtype);
	fprintf(ptr, "\n");

	printf("Enter bug priority:\n");
	scanf(" %[^\n]s", bugpriority);

	fprintf(ptr, "BUG PRIORITY: %s\n",
			bugpriority);
	fprintf(ptr, "\n");

	
	printf("Enter the bug description:\n");
	scanf(" %[^\n]s", bugdescription);

	fprintf(ptr, "BUG DESCRIPTION: %s\n",
			bugdescription);
	fprintf(ptr, "\n");

	printf("Status of bug:\n");
	printf("1. NOT YET ASSIGNED\n");
	printf("2.IN PROCESS\n 3.FIXED\n");
	printf("4.DELIVERED\n ENTER YOUR CHOICE:");

	int j;
	scanf("%d", &j);

	fprintf(ptr, "DATE AND TIME: %s",
			ctime(&CurrentTime));

	fprintf(ptr, "BUG STATUS:");

	switch (j) {
	case 1:
		fprintf(ptr, "NOT YET ASSIGNED\n");
		break;
	case 2:
		fprintf(ptr, "IN PROCESS\n");
		break;
	case 3:
		fprintf(ptr, "FIXED\n");
		break;
	case 4:
		fprintf(ptr, "DELIVERED\n");
		break;
	default:
		printf("invalid choice\n");
		break;
	}

	fclose(ptr);
}

void changestatus()
{
	printf("*************");
	printf("Change status");
	printf("**************\n");


	time_t CurrentTime;
	time(&CurrentTime);

	FILE* file;
	char name[50];

	printf("Enter file name:\n");
	scanf("%s", name);
	char ex[] = ".txt";
	strcat(name, ex);

	file = fopen(name, "a");

	printf("\n 1. NOT YET ASSIGNED\n");
	printf(" 2.IN PROCESS\n 3.FIXED\n");
	printf(" 4.DELIVERED\n ENTER YOUR CHOICE:");


	int k;
	scanf("%d", &k);

	fprintf(file, "\n");
	fprintf(file, "DATE AND TIME : %s",
			ctime(&CurrentTime));

	fprintf(file, "BUG STATUS:");


	switch (k) {
	case 1:
		fprintf(file, "NOT YET ASSIGNED\n");
		break;
	case 2:
		fprintf(file, "IN PROCESS\n");
		break;
	case 3:
		fprintf(file, "FIXED\n");
		break;
	case 4:
		fprintf(file, "DELIVERED\n");
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	fclose(file);
}

void report()
{
	printf("**********");
	printf("REPORT");
	printf("**********\n");

	FILE* fp;
	char name[50];

	printf("Enter file name:\n");
	scanf("%s", name);
	char ex[] = ".txt";
	strcat(name, ex);

	fp = fopen(name, "r");

	char ch;
	ch = getc(fp);

	while (ch != EOF) {
		printf("%c", ch);
		ch = getc(fp);
	}

	fclose(fp);
	getch();
}

int main()
{
	printf("***************");
	printf("BUG TRACKING SYSTEM");
	printf("***************\n");

	int number, i = 1;
	int id = 0;

	while (i != 0) {
		printf("\n1. FILE A NEW BUG\n");
		printf("2. CHANGE THE STATUS OF THE BUG\n");
		printf("3. GET BUG REPORT\n4. EXIT");
		printf("\n\n ENTER YOUR CHOICE:");

		scanf("%d", &number);

		switch (number) {
		case 1:
			id++;

			filebug(id);
			break;
		case 2:

			
			changestatus();
			break;
		case 3:

			report();
			break;
		case 4:
			i = 0;
			break;
		default:
			printf("\ninvalid entry");
			break;
		}
	}
    return 0;
}
