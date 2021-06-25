#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define PI 3.14

struct point
{
	int x, y;
};
struct circle
{
	struct point center;
	double radius;
};

void main()
{
	struct circle myCircle;
	printf("원의 중심의 좌표를 입력하시오: ");
	scanf("%d %d", &myCircle.center.x, &myCircle.center.y);
	printf("원의 반지름을 입력하시오: ");
	scanf("%lf", &myCircle.radius);
	printf("원의 중심의 좌표: (%d, %d)\n원의 반지름의 길이: %lf\n", myCircle.center.x, myCircle.center.y, myCircle.radius);
	printf("원의 둘레: %f\n", 2 * myCircle.radius * PI);
	printf("원의 넓이: %f\n", myCircle.radius * myCircle.radius * PI);
}