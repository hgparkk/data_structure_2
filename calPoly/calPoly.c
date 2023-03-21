
#include <stdio.h>
#include <math.h>
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
    for (i = 0; i <= p.degree; i++)
        scanf("%f", p.coef + i);

    return p;
}

void print_poly(Polynomial p, char str[])
{
    int i;
    printf("\t%s", str);
    for (i = 0; i < p.degree; i++)
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
        for (i = 0; i <= b.degree; i++)
            p.coef[i + (p.degree - b.degree)] += b.coef[i];
    }
    else
    {
        p = b;
        for (i = 0; i <= a.degree; i++)
            p.coef[i + (p.degree - a.degree)] += a.coef[i];
    }
    return p;
}

double Cal_poly(Polynomial p, double x)
{
    double result = 0;
    int i;

    for(i=0;i<p.degree;i++)
    {
        result += p.coef[i] * pow(x, (double)(p.degree-i));
    }
    result += p.coef[p.degree];

    return result;
}

int main()
{
    Polynomial a, b, c;
    double a1, b1, c1;
    a = read_poly();
    b = read_poly();
    c = add_poly(a, b);
    print_poly(a, "A=");
    print_poly(b, " B= ");
    print_poly(c, " A+B= ");
    a1 = Cal_poly(a, 3.0);
    b1 = Cal_poly(b, 3.0);
    c1 = Cal_poly(c, 3.0);
    printf("A= %f\n", a1);
    printf("B= %f\n", b1);
    printf("A+B= %f\n", c1);
}