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
		printf("학번을 입력하시오: ");
		scanf("%d", &list[i].number);
		printf("입력을 입력하시오: ");
		scanf("%s", list[i].name);
		printf("학점을 입력하시오(실수): ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("이름 : %s, 학점 : %f\n", list[i].name, list[i].grade);
	}
}