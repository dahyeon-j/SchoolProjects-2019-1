#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct _employee
{
	int number;
	char name[20]; // �̸�
	int phone_number;
	int age;
} employee;

void main()
{
	employee list[10];

	for (int i = 0; i < 10; i++)
	{
		printf("��� �̸� ��ȭ��ȣ ����: ");
		scanf("%d %s %d %d", &list[i].number, list[i].name, &list[i].phone_number, &list[i].age);
	}

	for (int i = 0; i < 10; i++)
	{
		if (20 <= list[i].age && list[i].age <= 30)
		{
			printf("�̸� = %s ���� = %d\n", list[i].name, list[i].age);
		}
	}
}