#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

// struct student : �л� ������ �����ϴ� ����ü
struct student
{
	char name[20]; // �̸�
	int number; // �й�
	float grade; // ����
};

int main(void)
{
	struct student list[5]; // struct student�� �迭

	int top = 0; // top : ���� ������ ���� �л��� �ε����� ����

	float average = 0; // ����� ����

	for (int i = 0; i < 5; i++) // 0���� 5���� �����ϴ� �ݺ���
	{
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", list[i].name); // �̸��� �Է� ����
		printf("�й��� �Է��Ͻÿ�: ");
		scanf("%d", &list[i].number); // �й��� �Է� ����
		printf("������ �Է��Ͻÿ�: ");
		scanf("%f", &list[i].grade); // ������ �Է� ����

		average += list[i].grade; // �Է� ���� ������ ����

		// ������ ������ top���� ������ �Ǵ�
		if (list[i].grade > list[top].grade) // �Է¹��� �л��� ������ ���� ������ ��
		{
			top = i; // top�� ��ü
		}
	}

	average /= 5.0; // ��� ���

	// ���� ������ ���� �л��� �̸�, �й�, ������ ���
	printf("<���� ������ ���� �л�>\n");
	printf("�̸� : %s\n", list[top].name);
	printf("�й� : %d\n", list[top].number);
	printf("���� : %.2f\n", list[top].grade);
	printf("��ü �л��� ��� : %.2f\n", average); // ����� ���
	printf("�ְ��� : %.2f", list[top].grade); // �ְ����� ���

}