#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char password[36]; // passowrd : 패스워드를 저장할 문자 배열

	printf("패스워드를 입력하시오: ");
	scanf_s("%s", password, sizeof(password)); // 패스워드를 입력 받아 password에 저장

	// number : 숫자가 존재하면 1
	// upper : 대문자가 존재하면 1
	// lower : 소문자가 존재하면 1
	// specialChar : 특수한 문자가 존재하면 1
	// continuous : 알파벳과 숫자 중 연속된 2문자 이상이 존재하면 1
	int number = 0, upper = 0, lower = 0, specialChar = 0, continuous = 0;

	for (int i = 0; i < strlen(password); i++) // 0부터 문자열길이 - 1까지 증가하는 반복문
	{
		char c = *(password + i); // c : 검사를 진행할 문자
		if (isdigit(c)) // c가 숫자 인지 검사
		{
			number = 1; // number에 1을 저장
			if (i > 0 && c - *(password + i - 1) == 1) // c가 앞의 문자와 연속적인지 검사
			{
				continuous = 1; // 연속적이면 1을 저장
			}
		}
		else if (isupper(c)) // c가 대문자인지 검사
		{
			upper = 1; // upper에 1을 저장
			if (i > 0 && c - *(password + i - 1) == 1) // c가 앞의 문자와 연속적인지 검사
			{
				continuous = 1; // 연속적이면 1을 저장
			}
		}
		else if (islower(c)) // c가 소문자 인지 검사
		{
			lower = 1; // lower에 1을 저장
			if (i > 0 && c - *(password + i - 1) == 1) // c가 앞의 문자와 연속적인지 검사
			{
				continuous = 1; // 연속적이면 1을 저장
			}
		}
		else if (c == '@' || c == '#' || c == '%') // c가 필요한 특수 문자인지 검사
		{
			specialChar = 1; // 필요한 특수문자이면 1을 저장
		}
	}

	if (number == 1 && upper == 1 && lower == 1 && specialChar == 1 && continuous == 0 && 10 <= strlen(password)) // 모든 조건을 만족 하는지 검사
	{
		printf("사용가능한 패스워드입니다!"); 
	}
	else // 사용 가능 하지 못한 패스워드 -> 만족시키지 못한 조건 모두 출력
	{
		if (strlen(password) < 10) // passoword의 길이가 10 미만일 때
		{
			printf("패스워드 크기는 최소 10 이상이어야 합니다.\n");
		}
		if (number == 0 || upper == 0 || lower == 0) // password가 하나 이상의 숫자, 소문자, 대문자를 포함하지 않을 때
		{
			printf("하나 이상의 숫자, 소문자, 대문자를 포함해야 합니다.\n");
		}
		if (specialChar == 0) // password가 필요한 특수문자가 없을 때
		{
			printf("특수문자 @, #, % 중 하나는 반드시 포함해야 합니다.\n");
		}
		if (continuous == 1) // 연속된 알파벳 또는 연속된 숫자가 있을 때
		{
			printf("알파벳과 숫자는 연속된 2문자 이상은 존재할 수 없습니다.");
		}
	}

	return 0;
}