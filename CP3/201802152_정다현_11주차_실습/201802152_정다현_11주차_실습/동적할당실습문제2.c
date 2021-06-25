#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct yellowBook
{
	char name[32];
	char phoneNumber[16];
};

int main()
{
	struct yellowBook *p;
	

	int n;
	printf("입력받을 전화번호의 개수 :");
	scanf("%d", &n);
	
	

	p = (struct yellowBook*)malloc(n * sizeof(struct yellowBook));

	if (p == NULL)
	{
		printf("메모리 할당 오류\n");
		exit(1);
	}


	for (int i = 0; i < n; i++)
	{
		printf("이름을 입력하시오 : ");
		scanf("%s", &p[i].name);
		printf("전화번호를 입력하시오 : ");
		scanf("%s", &p[i].phoneNumber);
	}
	printf(" 저장된 정보들\n");
	printf("====================================\n");
	printf("=   이름                  전화번호  =\n");
	printf("====================================\n");
	
	for (int i = 0; i < n; i++)
	{
		printf("%-16s", p[i].name);
		printf("%-16s\n", p[i].phoneNumber);
	}

}