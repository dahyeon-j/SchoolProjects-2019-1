#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

// struct student : 학생 정보를 저장하는 구조체
struct student
{
	char name[20]; // 이름
	int number; // 학번
	float grade; // 평점
};

int main(void)
{
	struct student list[5]; // struct student의 배열

	int top = 0; // top : 가장 평점이 높은 학생의 인덱스를 저장

	float average = 0; // 평균을 저장

	for (int i = 0; i < 5; i++) // 0에서 5까지 증가하는 반복문
	{
		printf("이름을 입력하시오: ");
		scanf("%s", list[i].name); // 이름을 입력 받음
		printf("학번을 입력하시오: ");
		scanf("%d", &list[i].number); // 학번을 입력 받음
		printf("평점을 입력하시오: ");
		scanf("%f", &list[i].grade); // 평점을 입력 받음

		average += list[i].grade; // 입력 받은 평점을 더함

		// 평점이 기존의 top보다 높은지 판단
		if (list[i].grade > list[top].grade) // 입력받은 학생의 평점이 가장 높은지 비교
		{
			top = i; // top을 교체
		}
	}

	average /= 5.0; // 평균 계산

	// 가장 평점이 높은 학생의 이름, 학번, 평점을 출력
	printf("<가장 평점이 높은 학생>\n");
	printf("이름 : %s\n", list[top].name);
	printf("학번 : %d\n", list[top].number);
	printf("평점 : %.2f\n", list[top].grade);
	printf("전체 학생의 평균 : %.2f\n", average); // 평균을 출력
	printf("최고점 : %.2f", list[top].grade); // 최고점을 출력

}