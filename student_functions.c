#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];
    char total_grades;
    char *grades;
} Student;

void printStudent(Student student)
{
    printf("Name of student: %s\n", student.name);
    printf("Total grades of student: %d\n", student.total_grades);
    for (int i = 0; i < student.total_grades; i++)
    {
        printf("Grade #%d: %d\n", i+1, student.grades[i]);
    }
}

Student createStudent()
{
    Student student;
    printf("Enter student name:\n");
    scanf("%s", &student.name);
    printf("Enter number of grades:\n");
    scanf("%d", (char*)(&student.total_grades));
    student.grades = (char*) malloc(sizeof(char)*student.total_grades);
    for (int i = 0; i<student.total_grades; i++)
    {
        printf("Enter grade #%d: ", i+1);
        scanf("%d", (char*)(student.grades+i));
    }
    return student;
}

void appendStudent(char * filename, Student student)
{
    FILE *fr = fopen(filename, "ab");
    fwrite(&student.name,sizeof(char)*20,1,fr);
    fwrite(&student.total_grades,sizeof(char)*1,1,fr);
    for (int i = 0; i<student.total_grades; i++)
    {
        fwrite(student.grades+i, sizeof(char),1,fr);
    }
    free(student.grades);
    fclose(fr);
}

void readStudents(char * filename)
{
    Student student;
    FILE *fr = fopen(filename, "r");

    while (!feof(fr))
    {
        fread(&student.name, sizeof(char)*20,1,fr);
        fread(&student.total_grades,sizeof(char),1,fr);
        student.grades = (char*) malloc(sizeof(char)*student.total_grades);
        for (int i = 0; i<student.total_grades;i++)
        {
            fread(student.grades+i, sizeof(char), 1, fr);
        }

        printStudent(student);
        free(student.grades);
        fgetc(fr);
        if (!feof(fr))
        {
            fseek(fr,-1,SEEK_CUR);
        }
    }
    fclose(fr);
}

int main()
{
    appendStudent("studentRecord.bin",createStudent());
    readStudents("studentRecord.bin");
}