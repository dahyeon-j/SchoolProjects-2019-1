#include <stdio.h>
#include <ctype.h>

#define DECODE 0
#define ENCODE 1

/*
시저(카이사르 암호 구현하기
*/

// carsar : 입력받은 문자열을 key 값을 사용하여 DECODE나 ENCODE하는 함수
// input : 입력 받은 문자열
// output : 처리한 문자를 저장할 문자열
// key : key 값
// type : ENCODE인지 DECODE인지 결정, 0 -> DECODE, 1 -> ENCODE
void caesar(char* input, char* output, int key, int type)
{
	// DECODE 모드일때
	if (type == DECODE)
	{
		while (*input) // '\0' NULL 문자가 나올 때까지
		{
			// 소문자 일 때 DECODE
			if ('a' <= *input && *input <= 'z')
			{
				if ((*input - key) < 'a') // 소문자의 아스키코드 범위를 넘어갔을 때
				{
					*output = *input - key + 26; // 26을 더하여 소문자 범위를 넘어가지 않도록 한다.
				}
				else // 소문자의 아스키코드 범위를 넘어가지 않았을 때
				{
					*output = *input - key; // 그대로 계산한다.
				}
			}
			// 대문자 일 때 DECODE
			if ('A' <= *input && *input <= 'Z')
			{
				if ((*input - key) < 'A') // 대문자의 아스키코드 범위를 넘어갔을 때
				{
					*output = *input - key + 26; // 26을 더하여 대문자 범위를 넘어가지 않도록 한다.
				}
				else // 대문자의 아스키코드 범위를 넘어가지 않았을 때
				{
					*output = *input - key; // 그대로 계산
				}
			}
			input++; // 입력 받은 문자 배열의 포인터 1 이동
			output++; // 치환한 문자를 저장할 문자 배열의 포인터 1 증가
		}
		*output = '\0'; // 마지막에 null 문자를 저장 -> 문자열의 끝을 나타내기 위해서
	}
	else // ENCODE 모드일 때
	{
		while (*input) // '\0' NULL 문자가 나올 때까지
		{
			// 소문자 일 때 ENCODE
			if ('a' <= *input && *input <= 'z')
			{
				if ('z' < (*input + key)) // 소문자의 아스키코드 범위를 넘어갔을 때
				{
					*output = *input + key - 26; // -26을 해서 소문자의 범위로 돌아오게 만든다.
				}
				else // 소문자의 아스키코드 범위를 넘어가지 않았을 때
				{
					*output = *input + key; // 그대로 처리 한다.
				}
			}
			// 대문자 일 때 ENCODE
			if ('A' <= *input && *input <= 'Z')
			{
				if ('Z' < (*input + key)) // 대문자의 아스키코드 범위를 넘어갔을 때
				{
					*output = *input + key - 26; // 26을 빼서 대문자의 범위를 넘지 않게 만든다.
				}
				else // 대문자의 아스키코드 범위를 넘어가지 않았을 때
				{
					*output = *input + key; // 그대로 처리한다.
				}
			}
			input++; // 입력 받은 문자 배열의 포인터 1 이동
			output++; // 치환한 문자를 저장할 문자 배열의 포인터 1 증가
		}
		*output = '\0'; // 마지막에 null 문자를 저장 -> 문자열의 끝을 나타내기 위해서
	}
}

int main(void)
{
	char inputString[33]; // 입력받은 문자열
	char encodedString[33]; // ENCODE한 문자열
	char decodedString[33]; // DECODE한 문자열

	// 문자열을 입력 받는다
	printf("please input your string : ");
	scanf_s("%s", inputString, sizeof(inputString)); // 문자열을 입력 받아 inputString에 저장

	int k; // 정수형 변수 k : key값을 입력받아 저장
	printf("please input your caesar Key number : ");
	scanf_s("%d", &k); // k 값을 입력

	caesar(inputString, encodedString, k, ENCODE); // inputString : ENCODE할 문자열, encodedString : ENCODE한 문자열을 저장할 문자열, k : key 값, ENCODE : ENCODE 할 것을 결정
	printf("Encoded string is : %s\n", encodedString); // ENCODE한 문자열을 출력

	// DECODE할 때 사용할 key 값을 다시 입력 받음
	printf("please input your caesar Key number : ");
	scanf_s(" %d", &k); // k 값을 입력

	caesar(encodedString, decodedString, k, DECODE); // inputString : DECODE할 문자열, decodedString : DECODE한 문자열을 저장할 문자열, k : key 값, DECODE : DECODE 할 것을 결정
	printf("Decoded string is : %s\n", decodedString); // DOCODE한 문자열을 출력
	
	return 0;
}