/*
프로그램 내용 : 구조체로 복소수를 출력하는 프로그램
실습일 : 2023.03.22
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>

typedef struct
{
    double real;
    double imag;
} Complex;

void print_complex(Complex c)
{
    printf("%4.1f+%4.1fi\n", c.real, c.imag);
}

void reset_complex(Complex c)
{
    c.real = c.imag = 0.0;
}

void main()
{
    Complex a = { 1.0,2.0 };
    Complex b = { 1.0,3.0 };
    printf("초기화 이전: ");
    print_complex(a);
    reset_complex(a);
    printf("초기화 이후: ");
    print_complex(a);
}