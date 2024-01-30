#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct student
{
	int rollNumber;
	int studentSemester;
	char DOB[15];
	char studentBranch[30];
	char studentName[30];
} Student ;

Student student_records[50] = {0};


void print_records()
{
	printf("Displaying all students record\n");

	for (int i=0; i<50; i++)
	{
		if (student_records[i].rollNumber > 0)
		{
		
			printf("************************************\n");
			printf("rollNumber	: %d\n", student_records[i].rollNumber);
			printf("studentSemester	: %d\n", student_records[i].studentSemester);
			printf("studentDOB	: %s\n", student_records[i].DOB);
			printf("studentBranch	: %s\n", student_records[i].studentBranch);
			printf("studentName	: %s\n", student_records[i].studentName);
		}
	}
			printf("************************************\n");		
	
}

void add_record()
{
	int freeIndex;

	for (int i = 0; i<50; i++)
	{
		if (student_records[i].rollNumber == 0)
		{
			freeIndex = i;
		}
	}

	printf("Add a new record\n");
	printf("Enter the rollNumber: ");
	scanf("%d", &student_records[freeIndex].rollNumber);
	printf("Enter the studentSemester: ");
	scanf("%d", &student_records[freeIndex].studentSemester);
	printf("Enter the DOB(mm/dd/yyyy): ");
	scanf("\n");
	scanf("%[^\n]s", &student_records[freeIndex].DOB);
	printf("Enter the studentBranch: ");
	scanf("\n");
	scanf("%[^\n]s", &student_records[freeIndex].studentBranch);
	printf("Enter the studentName: ");
	scanf("\n");
	scanf("%[^\n]s", &student_records[freeIndex].studentName);
	printf("Record added successfully\n");
	
}

int delete_record()
{
	int rollNumber;
	printf("Delete a record\n");
	printf("Enter the roll number of the student:\n");
	scanf("\n");
	scanf("%d", &rollNumber);

	for (int i=0; i<50; i++)
	{
		if (student_records[i].rollNumber == rollNumber)
		{
			student_records[i].rollNumber = 0;
			printf("Record deleted successfully\n");
			return 0;
		}
	}

	printf("Record not found\n");
	return 0;
	
}


int main()
{
	int input;

	printf("Student record management program\n");

	for (;;)
	{

		printf("Display all records  -->1\n");
		printf("Add new record	     -->2\n");
		printf("delete a record      -->3\n");
		printf("exit application     -->0\n");
		printf("Enter your option here: ");
		scanf("%d", &input);


		switch (input)
		{
			case 1:
				print_records();
				break;
			case 2:
				add_record();
				break;
			case 3:
				delete_record();
				break;
			case 4:
				exit(0);
			default:
				exit(0);
		}

	}

	return 0;
}
