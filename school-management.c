#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char student_name[50];
    int student_id;
    float student_grade;
} Student;

typedef struct course
{
    char course_name[50];
    float course_grade;
    int numStudents;
    Student *course_students;
} Course;

typedef struct school
{
    char school_name[50];
    int numCourses;
    Course *school_courses;
} School;

Student createStudent()
{
    Student temp;
    printf("Enter the student's name: \n");
    scanf("%*c%[^\n]", &temp.student_name);
    printf("Enter the student's ID: \n");
    scanf("%d", &temp.student_id);
    printf("Enter their grade in this course: \n");
    scanf("%f", &temp.student_grade);

    return temp;
}

Course createCourse()
{
    Course newCourse;
    float num;
    float den;
    float avg;

    printf("Enter the name of the course: \n");
    scanf("%*c%[^\n]", &newCourse.course_name);
    printf("How many students in the course?: \n");
    scanf("%d", &newCourse.numStudents);
    newCourse.course_students = (Student*) malloc(sizeof(Student)*newCourse.numStudents);

    for (int i = 0; i<newCourse.numStudents; i++)
    {
        printf("Student #%d:\n", i+1);
        *(newCourse.course_students+i) = createStudent();
    }

    for (int i = 0; i<newCourse.numStudents; i++)
    {
        num = num + (*(newCourse.course_students+i)).student_grade;
        den++;
    }

    avg = num/den;

    newCourse.course_grade = avg;

    return newCourse;

}

School createSchool()
{
    School temp;
    printf("What is the name of this school?: \n");
    scanf("%[^\n]%*c", &temp.school_name);
    printf("How many courses are there in this school?: \n");
    scanf("%d", &temp.numCourses); 
    temp.school_courses = (Course*) malloc(sizeof(Course)*temp.numCourses);

    for (int i = 0; i<temp.numCourses; i++)
    {
        printf("COURSE #%d: \n", i+1);
        *(temp.school_courses+i) = createCourse();
    }
    return temp;
}

void printStudent(Student student)
{
    printf("Name: %s    ID: %d    Grade: %f \n", student.student_name, student.student_id, student.student_grade);
}

void printCourse(Course course)
{
    printf("Course name: %s\n", course.course_name);
    printf("Average grade: %f\n", course.course_grade);
    
    printf("Students enrolled in course:\n");
    for (int i=0; i<course.numStudents; i++)
    {
        printStudent(*(course.course_students+i));
    }
}

void printSchool(School school)
{
    printf("%s\n", school.school_name);
    printf("Courses offered: \n");

    for (int i = 0; i < school.numCourses; i++)
    {
        printf("COURSE #%d:\n", i+1);
        printCourse(*(school.school_courses+i));
    }
    
}

int checkInCourse(int id, Course course)
{
    for (int i = 0; i<course.numStudents; i++)
    {
        if((*(course.course_students+i)).student_id == id)
        {
            printf("Student IS in course!\n");
            return 1;
        }
    }
    printf("Student IS NOT in course!\n");
    return 0;
}

int checkInSchool(int id, School school)
{
    for (int i = 0; i<school.numCourses; i++)
    {
        if (checkInCourse(id, (*(school.school_courses+i))))
        {
            printf("Student IS in school!\n");
            return 1;
        }
    }
    printf("Student IS NOT in school!\n");
    return 0;
}

void printStudentCourses(int id, School school)
{
    printf("Student is in the following courses:\n");
    for (int i = 0; i<school.numCourses; i++)
    {
        if (checkInCourse(id, *(school.school_courses+i)))
        {
            printf("%s\n", (*(school.school_courses+i)).course_name);
        }
    }
}

void printFailedStudents(int passing_grade, Course course)
{
    printf("Students who FAILED this course:\n");

    for (int i = 0; i<course.numStudents; i++)
    {
        if ((*(course.course_students+i)).student_grade<passing_grade)
        {
            printf("%s\n", (*(course.course_students+i)).student_name);
        }
    }
}

void printPassedStudents(int passing_grade, Course course)
{
    printf("Students who PASSED this course:\n");

    for (int i = 0; i<course.numStudents; i++)
    {
        if ((*(course.course_students+i)).student_grade>=passing_grade)
        {
            printf("%s\n", (*(course.course_students+i)).student_name);
        }
    }
}

void printPassedCourses(int passing_grade, School school)
{
    printf("The following courses have a PASS average grade:\n");

    for (int i = 0; i<school.numCourses;i++)
    {
        if ((*(school.school_courses+i)).course_grade >= passing_grade)
        {
            printf("%s", (*(school.school_courses+i)).course_name);
        }
    }
}

void printFailedCourses(int passing_grade, School school)
{
    printf("The following courses have a FAIL average grade:\n");

    for (int i = 0; i<school.numCourses;i++)
    {
        if ((*(school.school_courses+i)).course_grade < passing_grade)
        {
            printf("%s", (*(school.school_courses+i)).course_name);
        }
    }
}

void printSchoolAverage(School school)
{
    float num = 0;
    float den = 0;
    float avg;
    printf("The school average for this school is:\n");

    for (int i = 0; i<school.numCourses;i++)
    {
        num = num + (*(school.school_courses+i)).course_grade;
        den++;
    }

    if (den == 0)
    {
        den = 1;
    }

    avg = num/den;

    printf("%f", avg);
}

void printSchoolHighestAverage(School school)
{
    float highestAvg = 0;
    int highestAvgIndex;
    printf("The course with the HIGHEST AVG in this school is:\n");

    for (int i = 0; i<school.numCourses; i++)
    {
        if ((*(school.school_courses+i)).course_grade > highestAvg)
        {
            highestAvg = (*(school.school_courses+i)).course_grade;
            highestAvgIndex = i;
        }
    }

    printf("%s\n", (*(school.school_courses+highestAvgIndex)).course_name);
}

int main()
{
    School school[10];
    school[0] = createSchool();

    printSchool(school[0]);

    return 0;
}