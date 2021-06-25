#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �л����� ������ ����ü
struct profileOfStudent
{
	char name[40]; // �̸�
	int studentNumber; // �й�
	double grade; // ����
};

typedef struct profileOfStudent profile; // struct profileOfStudent�� profile�� ����ȭ

void appendProfile(FILE *f); // �������� �߰�

int main()
{
	char fname[] = "ProfileOfStudents.bin"; // ����
	FILE *f; // ���� ������

	// ������ ������ ���� ��� ó��
	if ((f = fopen(fname, "ab+")) == NULL) // ������ ������ ���� ���
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1); // ������������ �����
	}

	// ���Ͽ� �Է�
	appendProfile(f);
	
	// �����͸� ������ �� ������
	rewind(f);
	
	profile students[5]; // ����ü profileOfStudent�� �迭
	double average = 0.0; // ���
	int top = 0; // ������ ���� ���� �л��� �ε���

	// �迭�� ����
	for (int i = 0; i < 5; i++)
	{
		fread(&students[i], sizeof(profile), 1, f); // ���Ͽ� �ִ� �����͸� �迭�� ����
		average += students[i].grade; // ������ ����
		top = (students[top].grade < students[i].grade? i : top); // ������ �� ���� �л��� �ε����� ����
	}

	average /= 5.0; // ����� ����

	// ������ ���� �л� ���
	printf("<���� ������ ���� �л�>\n");
	printf("�̸� : %s, �й� : %d, ���� : %.2lf\n", students[top].name, students[top].studentNumber, students[top].grade);
	printf("��� : %.2lf\t�ְ��� : %.2lf", average, students[top].grade); // ��հ��� �ְ��� ���
	fclose(f);

	return 0;
}

// ���Ͽ� �����͸� �Է��ϴ� �Լ�
// *f: �����͸� �Է��� ������ ������
void appendProfile(FILE *f)
{
	profile student = { 0 };
	char line[80];

	printf("�߰��� �̸�, �й�, ������ �Է��ϼ���(�̸� �й� ����)\n");

	for(int i = 0; i < 5; i++) // 0���� 4���� �� 5ȸ�� �����ϴ� �ݺ���
	{
		fgets(line, 80, stdin); // �ܼ� â���� �Է��� ����
		sscanf_s(line, "%s %d %lf", student.name, 40, &student.studentNumber, &student.grade);
		fwrite(&student, sizeof(profile), 1, f); // ���Ͽ� �Է°��� ����
	}
}

