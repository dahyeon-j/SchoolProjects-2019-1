#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
��° file�� ������ �ι�° file�� �����ϴ� ���α׷�
�������� token�� �����ϰ� ��� token�� �� �� ���ڴ� �빮�ڷ� ��ȯ
*/

int main()
{
	FILE *src = fopen("src.txt", "r"); // ������ �ԷµǾ� �ִ� ����
	FILE *dest = fopen("dest.txt", "w"); // ������ ��ȯ�Ͽ� �Է��� ����

	char c; // ���� �ϳ��� �޴� ����


	int flag = 1; // �빮�ڸ� �Է����� ������ �Ǵ��ϴ� ���� 1�̸� �빮�ڷ� 0�̸� �׳�

	fread(&c, 1, 1, src); // src������ ���ڸ� �ϳ� �о��

	while (!feof(src)) // src ������ �������� �ƴ� ���� ����
	{


		if (flag == 1)
		{
			fprintf(dest, "%c", toupper(c)); // ���ڸ� ����
			flag = 0; // flag�� 0�� ����
		}
		else
		{
			fprintf(dest, "%c", c); // ���ڸ� ����
		}

		// �����̸� ���� ���� �빮�ڷ� ���� �غ�
		if (c == ' ')
		{
			flag = 1; // flag�� 1�� ����
		}


		fread(&c, 1, 1, src); // src������ ���ڸ� �ϳ� �о��

	}

	fclose(src); // �����͸� ����
	fclose(dest); // �����͸� ����

	return 0;
}