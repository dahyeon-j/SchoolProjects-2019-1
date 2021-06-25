#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
�� ���� �ؽ�Ʈ ������ ���Ͽ�
������ �ٸ����� �˷��ִ� ���α׷�
*/

void compareFiles(char *fname1, char *fname2, FILE *f1, FILE *f2); // ������ ���ϴ� �Լ�

int main()
{
	// ������ �̸�
	char fname[] = "sample.txt";
	char f1name[] = "sample1.txt";
	char f2name[] = "sample2.txt";
	// ������ ������
	FILE *f;
	FILE *f1;
	FILE *f2;

	// ������ ������ ���� ��
	if ((f = fopen(fname, "r")) == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
	}
	if ((f1 = fopen(f1name, "r")) == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
	}
	if ((f2 = fopen(f2name, "r")) == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
	}


	compareFiles(fname, f1name, f, f1); // f�� f1 ��
	compareFiles(fname, f2name, f, f2); // f�� f2 ��

	return 0;
}

// ������ ���ϴ� �Լ�
// fname1: ���� 1�� �̸�
// fname2: ���� 2�� �̸�
// f1 : ���� 1�� ������
// f2 : ���� 2�� ������
void compareFiles(char *fname1, char *fname2, FILE *f1, FILE *f2)
{
	// ���� �̸� ���
	printf("ù ��° ���� �̸� : %s\n", fname1); // ���� 1 �̸� ���
	printf("�� ��° ���� �̸� : %s\n", fname2); // ���� 2 �̸� ���

	fseek(f1, 0, SEEK_END); // ������ ���κ�
	fseek(f2, 0, SEEK_END); // ������ �� �κ�

	// ������ ���̰� �ٸ� ��
	if (ftell(f1) != ftell(f2))
	{
		printf("�� ������ ���� �ٸ��ϴ�.\n\n"); // ������ ���� �ٸ� ���
		return;
	}

	rewind(f1); // ���� 1�� �������� ��ġ�� �� ������ �ű�
	rewind(f2); // ���� 2�� �������� ��ġ�� �� ������ �ű�

	char c1; // ����1�� ���ڸ� �޾ƿ�
	char c2; // ����2�� ���ڸ� �޾ƿ�

	while (!feof(f1)) // ���� 1�� �� ���� ������
	{
		fread(&c1, 1, 1, f1); // ���� 1�� �� ���ڸ� �о��
		fread(&c2, 1, 1, f2); // ���� 2�� �� ���ڸ� �о��
		if (c1 != c2) // �޾ƿ� ���ڰ� �ٸ� ��
		{
			printf("�� ������ ���� �ٸ��ϴ�.\n\n"); // ������ ���� �ٸ� ���
			return;
		}

	}

	printf("�� ������ ���� �����ϴ�.\n\n"); // ������ ���� ���
}