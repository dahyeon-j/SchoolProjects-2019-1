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
	printf("�Է¹��� ��ȭ��ȣ�� ���� :");
	scanf("%d", &n);
	
	

	p = (struct yellowBook*)malloc(n * sizeof(struct yellowBook));

	if (p == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}


	for (int i = 0; i < n; i++)
	{
		printf("�̸��� �Է��Ͻÿ� : ");
		scanf("%s", &p[i].name);
		printf("��ȭ��ȣ�� �Է��Ͻÿ� : ");
		scanf("%s", &p[i].phoneNumber);
	}
	printf(" ����� ������\n");
	printf("====================================\n");
	printf("=   �̸�                  ��ȭ��ȣ  =\n");
	printf("====================================\n");
	
	for (int i = 0; i < n; i++)
	{
		printf("%-16s", p[i].name);
		printf("%-16s\n", p[i].phoneNumber);
	}

}