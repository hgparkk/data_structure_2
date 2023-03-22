/*
프로그램 내용 : 문자열과 관련된 몇가지 기능을 실습하는 프로그램
실습일 : 2023.03.22
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[60] = "C language is ";
	char s2[60] = "a good programming language.";
	char s3[60];

	char s[4][50];
	int length, i;
	i = 0;

	length = strlen(s1);
	printf("String length is %d \n", length);

	strcpy(s3, s1);
	printf("s3 = %s \n", s3);

	if (strcmp(s1, s3) == 0)
		printf("s1 is equal to s3 \n");
	else
		printf("s1 is not equal to s3 \n");

	if (strcmp(s1, s2) == 0)
		printf("s1 is equal to s2 \n");
	else
		printf("s1 is not equal to s2 \n");
	strcat(s1, s2);
	printf("s1 = %s \n", s1);

	for (i = 0; i < 4; i++)
	{
		printf("Please enter a name ");
		scanf("%s", s[i]);
	}

	for (i = 0; i < 4; i++)
	{
		printf("\n Name is %s", s[i]);
	}

	return 0;
}