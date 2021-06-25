#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n;

	printf("입력할 정수의 개수 : ");
	scanf("%d", &n);

	int *p;
	p = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		printf("%d 번째 정수 입력 : ", i);
		scanf("%d", &p[i]);
	}
	printf("\n");


	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 정수는 : %d\n", i, p[i]);
		sum += p[i];
	}

	printf("정수의 총 합 : %d\n", sum);

	return 0;
}