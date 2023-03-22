/*
프로그램 내용 : 두 수를 입력받아 각각 A와 B배열에 넣고 각 배열의 가장 큰 수 두개를 비교해 더 큰 배열을 출력하는 프로그램
실습일 : 2023.03.22
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>

int find_max_score(int score[], int n)
{
	int i, tmp;
	tmp = score[0];
	for (i = 0; i < n; i++)
		if (score[i] > tmp)
			tmp = score[i];
	return tmp;
}


int main()
{
	int A[5], B[5];
	int i, maxA, maxB;

	for (i = 0; i < 5; i++)
	{
		printf("Please, enter two numbers >>");
		scanf("%d %d", &A[i], &B[i]);
	}
	maxA = find_max_score(A, 5);
	maxB = find_max_score(B, 5);

	if (maxA > maxB)
		printf(" Array A ");
	else if (maxA < maxB)
		printf(" Array B ");
	else
		printf(" Array A and Array B have same maximum number ");

	return 0;
}