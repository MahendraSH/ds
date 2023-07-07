//Passing  structure to function
#include<stdio.h>

typedef long int lint;
lint  x = 100;

typedef struct stu
{
char name[20];
int usn;
float cgpa;
} student;

// call by value
void display(student s)
{
    printf("Name = %s\n", s.name);
    printf("USN = %d\n", s.usn);
    printf("CGPA = %.2f\n\n", s.cgpa);
}

// call by reference
void display1(student *spr)
{
    printf("Name = %s\n", spr->name);
    printf("USN = %d\n", spr->usn);
    printf("CGPA = %.2f\n\n", spr->cgpa);
}

int main()
{
lint a,b;
student s1;
strcpy(s1.name,"Amit");
s1.usn = 1234;
s1.cgpa = 8.97;

display(s1);
display1(&s1);
return 0;
}

/*
OUTPUT:
    Name = Amit
    USN = 1234
    CGPA = 8.97

    Name = Amit
    USN = 1234
    CGPA = 8.97
*/
