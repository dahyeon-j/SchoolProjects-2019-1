#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 학생들의 프로필 구조체
struct profileOfStudent
{
	char name[40]; // 이름
	int studentNumber; // 학번
	double grade; // 평점
};

typedef struct profileOfStudent profile; // struct profileOfStudent를 profile로 간소화

void appendProfile(FILE *f); // 프로필을 추가

int main()
{
	char fname[] = "ProfileOfStudents.bin"; // 파일
	FILE *f; // 파일 포인터

	// 파일이 열리지 않을 경우 처리
	if ((f = fopen(fname, "ab+")) == NULL) // 파일이 열리지 않을 경우
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1); // 비정상적으로 종료됨
	}

	// 파일에 입력
	appendProfile(f);
	
	// 포인터를 파일의 맨 앞으로
	rewind(f);
	
	profile students[5]; // 구조체 profileOfStudent의 배열
	double average = 0.0; // 평균
	int top = 0; // 평점이 제일 높은 학생의 인덱스

	// 배열에 저장
	for (int i = 0; i < 5; i++)
	{
		fread(&students[i], sizeof(profile), 1, f); // 파일에 있는 데이터를 배열에 저장
		average += students[i].grade; // 점수를 누적
		top = (students[top].grade < students[i].grade? i : top); // 평점이 더 높은 학생의 인덱스를 저장
	}

	average /= 5.0; // 평균을 구함

	// 평점이 높은 학생 출력
	printf("<가장 평점이 높은 학생>\n");
	printf("이름 : %s, 학번 : %d, 평점 : %.2lf\n", students[top].name, students[top].studentNumber, students[top].grade);
	printf("평균 : %.2lf\t최고점 : %.2lf", average, students[top].grade); // 평균값과 최고점 출력
	fclose(f);

	return 0;
}

// 파일에 데이터를 입력하는 함수
// *f: 데이터를 입력할 파일의 포인터
void appendProfile(FILE *f)
{
	profile student = { 0 };
	char line[80];

	printf("추가할 이름, 학번, 평점을 입력하세요(이름 학번 평점)\n");

	for(int i = 0; i < 5; i++) // 0부터 4까지 총 5회를 실행하는 반복문
	{
		fgets(line, 80, stdin); // 콘솔 창에서 입력을 받음
		sscanf_s(line, "%s %d %lf", student.name, 40, &student.studentNumber, &student.grade);
		fwrite(&student, sizeof(profile), 1, f); // 파일에 입력값을 저장
	}
}

