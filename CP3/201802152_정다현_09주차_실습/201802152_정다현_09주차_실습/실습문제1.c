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
	printf("���� �߽��� ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d %d", &myCircle.center.x, &myCircle.center.y);
	printf("���� �������� �Է��Ͻÿ�: ");
	scanf("%lf", &myCircle.radius);
	printf("���� �߽��� ��ǥ: (%d, %d)\n���� �������� ����: %lf\n", myCircle.center.x, myCircle.center.y, myCircle.radius);
	printf("���� �ѷ�: %f\n", 2 * myCircle.radius * PI);
	printf("���� ����: %f\n", myCircle.radius * myCircle.radius * PI);
}