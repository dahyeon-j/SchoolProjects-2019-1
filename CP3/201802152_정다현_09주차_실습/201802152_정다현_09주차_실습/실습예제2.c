#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define SIZE 3

struct student
{
	int number;
	char name[20];
	double grade;
};

void main()
{
	struct student list[SIZE];
	int i;
	char li[10];

	for (i = 0; i < SIZE; i++)
	{
		printf("�й��� �Է��Ͻÿ�: ");
		scanf("%d", &list[i].number);
		printf("�Է��� �Է��Ͻÿ�: ");
		scanf("%s", list[i].name);
		printf("������ �Է��Ͻÿ�(�Ǽ�): ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("�̸� : %s, ���� : %f\n", list[i].name, list[i].grade);
	}
}