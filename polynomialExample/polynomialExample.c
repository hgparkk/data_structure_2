﻿/*
프로그램 내용 : 최고 차수와 각 항의 계수를 두번 입력받아 다항식 두개를 출력하는 프로그램
실습일 : 2023.03.22
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#define MAX_DEGREE 101

typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
} Polynomial;

Polynomial read_poly()
{
    int i;
    Polynomial p;

    printf("다항식의 최고 차수를 입력하시오: ");
    scanf("%d", &p.degree);
    printf("각 항의 계수를 입력하시오 (총 %d개):", p.degree + 1);
    for (i = 0;i <= p.degree;i++)
        scanf("%f", p.coef + i);
    return p;
}

void print_poly(Polynomial p, char str[])
{
    int i;
    printf("\t%s", str);
    for (i = 0;i < p.degree;i++)
        printf("%5.1f x^%d + ", p.coef[i], p.degree - i);
    printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial add_poly(Polynomial a, Polynomial b)
{
    int i;
    Polynomial p;
    if (a.degree > b.degree)
    {
        p = a;
        for (i = 0;i <= b.degree;i++)
            p.coef[i + (p.degree - b.degree)] += b.coef[i];
    }
    else
    {
        p = b;
        for (i = 0;i <= a.degree;i++)
            p.coef[i + (p.degree - a.degree)] += a.coef[i];
    }
    return p;
}

int main()
{
    Polynomial a, b, c;
    a = read_poly();
    b = read_poly();
    c = add_poly(a, b);
    print_poly(a, " A= ");
    print_poly(b, " B= ");
    print_poly(c, " A+B= ");
}