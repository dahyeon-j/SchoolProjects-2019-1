#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
번째 file의 내용을 두번째 file에 변경하는 프로그램
공간으로 token을 구별하고 모든 token의 맨 앞 문자는 대문자로 변환
*/

int main()
{
	FILE *src = fopen("src.txt", "r"); // 문장이 입력되어 있는 파일
	FILE *dest = fopen("dest.txt", "w"); // 문장을 변환하여 입력할 파일

	char c; // 문자 하나씩 받는 변수


	int flag = 1; // 대문자를 입력할지 안할지 판단하는 변수 1이면 대문자로 0이면 그냥

	fread(&c, 1, 1, src); // src파일의 문자를 하나 읽어옴

	while (!feof(src)) // src 파일의 마지막이 아닌 동안 실행
	{


		if (flag == 1)
		{
			fprintf(dest, "%c", toupper(c)); // 문자를 저장
			flag = 0; // flag에 0을 저장
		}
		else
		{
			fprintf(dest, "%c", c); // 문자를 저장
		}

		// 공백이면 다음 문자 대문자로 만들 준비
		if (c == ' ')
		{
			flag = 1; // flag에 1을 저장
		}


		fread(&c, 1, 1, src); // src파일의 문자를 하나 읽어옴

	}

	fclose(src); // 포인터를 닫음
	fclose(dest); // 포인터를 닫음

	return 0;
}