#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ���׽��� ó���ϱ� ���� ����ü
struct polynomial
{
	int coeff; // ���
	int exp; // ����
};

void main()
{
	struct polynomial list[5]; // 5���� ����� ����
	int n = 0; // ��� ������ ���Ǿ����� Ȯ���� �� �ִ� ���� ���

	for (int i = 0; i < 5; i++) // 0���� 4���� 5�� �����ϴ� �ݺ���
	{
		printf("poly[%d].coeff = ", i);
		scanf("%d", &list[i].coeff); // ����� �Է� ����
		printf("poly[%d].exp = ", i);
		scanf("%d", &list[i].exp); // ������ �Է� ����
		if (list[i].exp == 0) break; // ������ 0�� �Է¹����� �Է��� ����

		n++; // n 1 ����
	}

	int x; // ���׽� ��꿡 ����� ��
	printf("x�� �Է��Ͻÿ�: ");
	scanf("%d", &x); // x�� �Է� ����

	int sum = 0, tmp; // sum : �����, tmp : ��� �߰��� ����� ��

	for (int i = 0; i < n; i++) // 0���� �Է¹��� ���� ������ �ε��� n-1���� ���� : n ��ŭ ����
	{
		tmp = list[i].coeff; // tmp�� ��� ������ �ʱ�ȭ

		for (int j = 0; j < list[i].exp; j++) // ������ ����ŭ ���ϱ⸦ �����ϴ� �ݺ���
		{
			tmp *= x; // x�� ����
		}

		sum += tmp; // sum�� �߰� ��갪�� ����

		if (list[i].exp == 0) break; // ������ 0�̵Ǹ� ��
	}

	printf("������� : %d", sum); // ����� ���

}