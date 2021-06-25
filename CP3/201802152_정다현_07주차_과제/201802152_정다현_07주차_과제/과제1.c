#include <stdio.h>
#include <ctype.h>

#define DECODE 0
#define ENCODE 1

/*
����(ī�̻縣 ��ȣ �����ϱ�
*/

// carsar : �Է¹��� ���ڿ��� key ���� ����Ͽ� DECODE�� ENCODE�ϴ� �Լ�
// input : �Է� ���� ���ڿ�
// output : ó���� ���ڸ� ������ ���ڿ�
// key : key ��
// type : ENCODE���� DECODE���� ����, 0 -> DECODE, 1 -> ENCODE
void caesar(char* input, char* output, int key, int type)
{
	// DECODE ����϶�
	if (type == DECODE)
	{
		while (*input) // '\0' NULL ���ڰ� ���� ������
		{
			// �ҹ��� �� �� DECODE
			if ('a' <= *input && *input <= 'z')
			{
				if ((*input - key) < 'a') // �ҹ����� �ƽ�Ű�ڵ� ������ �Ѿ�� ��
				{
					*output = *input - key + 26; // 26�� ���Ͽ� �ҹ��� ������ �Ѿ�� �ʵ��� �Ѵ�.
				}
				else // �ҹ����� �ƽ�Ű�ڵ� ������ �Ѿ�� �ʾ��� ��
				{
					*output = *input - key; // �״�� ����Ѵ�.
				}
			}
			// �빮�� �� �� DECODE
			if ('A' <= *input && *input <= 'Z')
			{
				if ((*input - key) < 'A') // �빮���� �ƽ�Ű�ڵ� ������ �Ѿ�� ��
				{
					*output = *input - key + 26; // 26�� ���Ͽ� �빮�� ������ �Ѿ�� �ʵ��� �Ѵ�.
				}
				else // �빮���� �ƽ�Ű�ڵ� ������ �Ѿ�� �ʾ��� ��
				{
					*output = *input - key; // �״�� ���
				}
			}
			input++; // �Է� ���� ���� �迭�� ������ 1 �̵�
			output++; // ġȯ�� ���ڸ� ������ ���� �迭�� ������ 1 ����
		}
		*output = '\0'; // �������� null ���ڸ� ���� -> ���ڿ��� ���� ��Ÿ���� ���ؼ�
	}
	else // ENCODE ����� ��
	{
		while (*input) // '\0' NULL ���ڰ� ���� ������
		{
			// �ҹ��� �� �� ENCODE
			if ('a' <= *input && *input <= 'z')
			{
				if ('z' < (*input + key)) // �ҹ����� �ƽ�Ű�ڵ� ������ �Ѿ�� ��
				{
					*output = *input + key - 26; // -26�� �ؼ� �ҹ����� ������ ���ƿ��� �����.
				}
				else // �ҹ����� �ƽ�Ű�ڵ� ������ �Ѿ�� �ʾ��� ��
				{
					*output = *input + key; // �״�� ó�� �Ѵ�.
				}
			}
			// �빮�� �� �� ENCODE
			if ('A' <= *input && *input <= 'Z')
			{
				if ('Z' < (*input + key)) // �빮���� �ƽ�Ű�ڵ� ������ �Ѿ�� ��
				{
					*output = *input + key - 26; // 26�� ���� �빮���� ������ ���� �ʰ� �����.
				}
				else // �빮���� �ƽ�Ű�ڵ� ������ �Ѿ�� �ʾ��� ��
				{
					*output = *input + key; // �״�� ó���Ѵ�.
				}
			}
			input++; // �Է� ���� ���� �迭�� ������ 1 �̵�
			output++; // ġȯ�� ���ڸ� ������ ���� �迭�� ������ 1 ����
		}
		*output = '\0'; // �������� null ���ڸ� ���� -> ���ڿ��� ���� ��Ÿ���� ���ؼ�
	}
}

int main(void)
{
	char inputString[33]; // �Է¹��� ���ڿ�
	char encodedString[33]; // ENCODE�� ���ڿ�
	char decodedString[33]; // DECODE�� ���ڿ�

	// ���ڿ��� �Է� �޴´�
	printf("please input your string : ");
	scanf_s("%s", inputString, sizeof(inputString)); // ���ڿ��� �Է� �޾� inputString�� ����

	int k; // ������ ���� k : key���� �Է¹޾� ����
	printf("please input your caesar Key number : ");
	scanf_s("%d", &k); // k ���� �Է�

	caesar(inputString, encodedString, k, ENCODE); // inputString : ENCODE�� ���ڿ�, encodedString : ENCODE�� ���ڿ��� ������ ���ڿ�, k : key ��, ENCODE : ENCODE �� ���� ����
	printf("Encoded string is : %s\n", encodedString); // ENCODE�� ���ڿ��� ���

	// DECODE�� �� ����� key ���� �ٽ� �Է� ����
	printf("please input your caesar Key number : ");
	scanf_s(" %d", &k); // k ���� �Է�

	caesar(encodedString, decodedString, k, DECODE); // inputString : DECODE�� ���ڿ�, decodedString : DECODE�� ���ڿ��� ������ ���ڿ�, k : key ��, DECODE : DECODE �� ���� ����
	printf("Decoded string is : %s\n", decodedString); // DOCODE�� ���ڿ��� ���
	
	return 0;
}