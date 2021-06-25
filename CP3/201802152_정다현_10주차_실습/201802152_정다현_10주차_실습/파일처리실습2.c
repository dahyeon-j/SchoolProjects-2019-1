#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char fname[] = "grade.txt";
	FILE *f;
	char name[30];
	int point1, point2, cnt = 0;

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	printf("�̸��� ����(�߰�, �⸻)�� �Է��ϼ���\n");
	scanf("%s %d %d", name, &point1, &point2);

	fprintf(f, "%d %s %d %d\n", ++cnt, name, point1, point2);
	fclose(f);

	if (fopen_s(&f, fname, "r") != 0)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}

	fscanf(f, "%d %s %d %d\n", &cnt, name, &point1, &point2);
	
	fprintf(stdout, "\n%6s%16s%10s%8s\n", "��ȣ", "�̸�", "�߰�", "�⸻");
	fprintf(stdout, "%5d%18s%8d%8d\n", cnt, name, point1, point2);
	fclose(f);

	return 0;
}