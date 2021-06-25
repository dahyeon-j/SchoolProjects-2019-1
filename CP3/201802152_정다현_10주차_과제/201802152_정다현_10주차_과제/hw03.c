#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
두 개의 텍스트 파일을 비교하여
같은지 다른지를 알려주는 프로그램
*/

void compareFiles(char *fname1, char *fname2, FILE *f1, FILE *f2); // 파일을 비교하는 함수

int main()
{
	// 파일의 이름
	char fname[] = "sample.txt";
	char f1name[] = "sample1.txt";
	char f2name[] = "sample2.txt";
	// 파일의 포인터
	FILE *f;
	FILE *f1;
	FILE *f2;

	// 파일이 열리지 않을 때
	if ((f = fopen(fname, "r")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
	}
	if ((f1 = fopen(f1name, "r")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
	}
	if ((f2 = fopen(f2name, "r")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
	}


	compareFiles(fname, f1name, f, f1); // f와 f1 비교
	compareFiles(fname, f2name, f, f2); // f와 f2 비교

	return 0;
}

// 파일을 비교하는 함수
// fname1: 파일 1의 이름
// fname2: 파일 2의 이름
// f1 : 파일 1의 포인터
// f2 : 파일 2의 포인터
void compareFiles(char *fname1, char *fname2, FILE *f1, FILE *f2)
{
	// 파일 이름 출력
	printf("첫 번째 파일 이름 : %s\n", fname1); // 파일 1 이름 출력
	printf("두 번째 파일 이름 : %s\n", fname2); // 파일 2 이름 출력

	fseek(f1, 0, SEEK_END); // 파일의 끝부분
	fseek(f2, 0, SEEK_END); // 파일의 끝 부분

	// 파일의 길이가 다를 때
	if (ftell(f1) != ftell(f2))
	{
		printf("두 파일은 서로 다릅니다.\n\n"); // 파일이 서로 다름 출력
		return;
	}

	rewind(f1); // 파일 1의 포인터의 위치를 맨 앞으로 옮김
	rewind(f2); // 파일 2의 포인터의 위치를 맨 앞으로 옮김

	char c1; // 파일1의 문자를 받아옴
	char c2; // 파일2의 문자를 받아옴

	while (!feof(f1)) // 파일 1을 다 읽을 때까지
	{
		fread(&c1, 1, 1, f1); // 파일 1의 한 글자를 읽어옴
		fread(&c2, 1, 1, f2); // 파일 2의 한 글자를 읽어옴
		if (c1 != c2) // 받아온 문자가 다를 때
		{
			printf("두 파일은 서로 다릅니다.\n\n"); // 파일이 서로 다름 출력
			return;
		}

	}

	printf("두 파일은 서로 같습니다.\n\n"); // 파일이 같음 출력
}