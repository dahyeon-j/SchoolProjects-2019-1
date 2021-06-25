#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 다항식을 처리하기 위한 구조체
struct polynomial
{
	int coeff; // 계수
	int exp; // 지수
};

void main()
{
	struct polynomial list[5]; // 5차수 계산을 위해
	int n = 0; // 몇개의 차수가 사용되었는지 확인할 수 있는 변수 사용

	for (int i = 0; i < 5; i++) // 0부터 4까지 5번 실행하는 반복문
	{
		printf("poly[%d].coeff = ", i);
		scanf("%d", &list[i].coeff); // 계수를 입력 받음
		printf("poly[%d].exp = ", i);
		scanf("%d", &list[i].exp); // 지수를 입력 받음
		if (list[i].exp == 0) break; // 지수로 0을 입력받으면 입력을 멈춤

		n++; // n 1 증가
	}

	int x; // 다항식 계산에 사용할 수
	printf("x를 입력하시오: ");
	scanf("%d", &x); // x를 입력 받음

	int sum = 0, tmp; // sum : 결과값, tmp : 계산 중간에 사용할 값

	for (int i = 0; i < n; i++) // 0부터 입력받은 수의 마지막 인덱스 n-1까지 실행 : n 만큼 실행
	{
		tmp = list[i].coeff; // tmp를 계수 값으로 초기화

		for (int j = 0; j < list[i].exp; j++) // 지수의 수만큼 곱하기를 실행하는 반복문
		{
			tmp *= x; // x를 곱함
		}

		sum += tmp; // sum에 중간 계산값을 더함

		if (list[i].exp == 0) break; // 지수가 0이되면 끝
	}

	printf("결과값은 : %d", sum); // 결과값 출력

}