#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
};
typedef struct personscore pscore;

void printhead();
int printscore(FILE *f);
void appendscore(FILE *f, int cnt);

int main()
{
	char fname[] = "score.bin";
	FILE *f;
	int cnt = 0;
	long offset = 0;

	if ((f = fopen(fname, "ab+")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	int readcnt = printscore(f);

	if (readcnt == 1)
	{
		pscore score;
		offset = (long)sizeof(pscore); // 구조체 하나의 크기
		// 파일의 마지막에서 마지막 학생을 읽기 위해 한 학생만큼 뒤로 이동
		fseek(f, -offset, SEEK_END);
		fread(&score, sizeof(pscore), 1, f);

		// 제일 마지막 자료의 번호를 찾기 위하여
		cnt = score.number;
		printf("\n제일 마지막 번호가 %d번 입니다.\n\n", cnt);
	}

	fseek(f, 0L, SEEK_END);
	appendscore(f, cnt);
	printscore(f);
	fclose(f);

	return 0;
}

void appendscore(FILE *f, int cnt)
{
	pscore score = { 0 };
	char line[80];

	printf("추가할 이름과 성적(중간, 기말, 퀴즈)을 입력하세요.\n\n");
	fgets(line, 80, stdin);
	while (!feof(stdin))
	{
		sscanf_s(line, "%s %d %d %d", score.name, 40, &score.mid, &score.final, &score.quiz);
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}
}

int printscore(FILE *f)
{
	// 파일의 맨 앞으로 이동
	rewind(f);
	pscore score;
	// 파일 f에 하나도 자료가 없으면 변수 readcnt = 0
	int readcnt = fread(&score, sizeof(pscore), 1, f);
	if (readcnt == 0)
	{
		printf("현재는 성적 정보가 하나도 없습니다. >>\n");
		return 0;
	}

	// 제목 출력
	printhead();
	while (!feof(f))
	{
		// 표준출력에 쓰기
		fprintf(stdout, "%6d%18s%8d%8d%8d\n", score.number, score.name ,score.mid, score.final, score.quiz);
		fread(&score, sizeof(pscore), 1, f);
	}
	fprintf(stdout, "%s\n", "-----------------------------------------------");

	return 1;
}

void printhead()
{
	printf("\n현재의 성적 내용은 >> \n");
	fprintf(stdout, "%s\n", "__________________________________________________");
	fprintf(stdout, "%8s%15s%10s%8s%8s\n", "번호", "이름", "중간", "기말", "퀴즈");
	fprintf(stdout, "%s\n", "__________________________________________________");
}
