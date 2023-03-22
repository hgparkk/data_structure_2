/*
프로그램 내용 : 구조체를 통해 학생 정보를 입력받고 가장 성적이 높은 학생을 출력하는 프로그램
실습일 : 2023.03.22
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    double score;
};

typedef struct student Student;
void printf_student(Student s);
Student Max_Student(Student s[], int n);

int main(void)
{
    struct student s1 = { 1,"park",80.5 }, s2;
    Student s[3];
    int i;

    s2.id = 2;
    strcpy(s2.name, "kim");
    printf_student(s1);

    for (i = 0; i < 3; i++) {
        printf("ID, name, score >>");
        scanf("%d %s %lf", &s[i].id, s[i].name, &s[i].score);
    }
    for (i = 0; i < 3; i++)
        printf_student(s[i]);
    s2 = Max_Student(s, 3);
    printf("The max score student is : \n");
    printf_student(s2);
    return 0;
}
void printf_student(Student s)
{
    printf("ID = %d, Name = %s, score = %lf \n", s.id, s.name, s.score);
}

Student Max_Student(Student s[], int n)
{
    int i;
    Student Max;

    Max = s[0];
    for (i = 1; i < n; i++)
        if (Max.score < s[i].score)
            Max = s[i];
    return Max;
}