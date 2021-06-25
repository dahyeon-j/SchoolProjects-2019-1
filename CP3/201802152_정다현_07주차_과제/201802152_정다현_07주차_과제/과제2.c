#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char password[36]; // passowrd : �н����带 ������ ���� �迭

	printf("�н����带 �Է��Ͻÿ�: ");
	scanf_s("%s", password, sizeof(password)); // �н����带 �Է� �޾� password�� ����

	// number : ���ڰ� �����ϸ� 1
	// upper : �빮�ڰ� �����ϸ� 1
	// lower : �ҹ��ڰ� �����ϸ� 1
	// specialChar : Ư���� ���ڰ� �����ϸ� 1
	// continuous : ���ĺ��� ���� �� ���ӵ� 2���� �̻��� �����ϸ� 1
	int number = 0, upper = 0, lower = 0, specialChar = 0, continuous = 0;

	for (int i = 0; i < strlen(password); i++) // 0���� ���ڿ����� - 1���� �����ϴ� �ݺ���
	{
		char c = *(password + i); // c : �˻縦 ������ ����
		if (isdigit(c)) // c�� ���� ���� �˻�
		{
			number = 1; // number�� 1�� ����
			if (i > 0 && c - *(password + i - 1) == 1) // c�� ���� ���ڿ� ���������� �˻�
			{
				continuous = 1; // �������̸� 1�� ����
			}
		}
		else if (isupper(c)) // c�� �빮������ �˻�
		{
			upper = 1; // upper�� 1�� ����
			if (i > 0 && c - *(password + i - 1) == 1) // c�� ���� ���ڿ� ���������� �˻�
			{
				continuous = 1; // �������̸� 1�� ����
			}
		}
		else if (islower(c)) // c�� �ҹ��� ���� �˻�
		{
			lower = 1; // lower�� 1�� ����
			if (i > 0 && c - *(password + i - 1) == 1) // c�� ���� ���ڿ� ���������� �˻�
			{
				continuous = 1; // �������̸� 1�� ����
			}
		}
		else if (c == '@' || c == '#' || c == '%') // c�� �ʿ��� Ư�� �������� �˻�
		{
			specialChar = 1; // �ʿ��� Ư�������̸� 1�� ����
		}
	}

	if (number == 1 && upper == 1 && lower == 1 && specialChar == 1 && continuous == 0 && 10 <= strlen(password)) // ��� ������ ���� �ϴ��� �˻�
	{
		printf("��밡���� �н������Դϴ�!"); 
	}
	else // ��� ���� ���� ���� �н����� -> ������Ű�� ���� ���� ��� ���
	{
		if (strlen(password) < 10) // passoword�� ���̰� 10 �̸��� ��
		{
			printf("�н����� ũ��� �ּ� 10 �̻��̾�� �մϴ�.\n");
		}
		if (number == 0 || upper == 0 || lower == 0) // password�� �ϳ� �̻��� ����, �ҹ���, �빮�ڸ� �������� ���� ��
		{
			printf("�ϳ� �̻��� ����, �ҹ���, �빮�ڸ� �����ؾ� �մϴ�.\n");
		}
		if (specialChar == 0) // password�� �ʿ��� Ư�����ڰ� ���� ��
		{
			printf("Ư������ @, #, % �� �ϳ��� �ݵ�� �����ؾ� �մϴ�.\n");
		}
		if (continuous == 1) // ���ӵ� ���ĺ� �Ǵ� ���ӵ� ���ڰ� ���� ��
		{
			printf("���ĺ��� ���ڴ� ���ӵ� 2���� �̻��� ������ �� �����ϴ�.");
		}
	}

	return 0;
}