#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main()
{
	int x = 2;
	int y = 2;
	printf("%d\n", SQUARE(x)); // 4
	printf("%d\n", SQUARE(3)); // 9
	printf("%f\n", SQUARE(1.2)); // 1.44
	printf("%d\n", SQUARE(x+3)); // 25
	printf("%d\n", 100/SQUARE(x)); // 25
	printf("%d\n", SQUARE(++x)); // ++x �� ��ó�� �⿡ ���鼭 ++�� 2�� �ȴ�. 4 * 4�� ��

	return 0;
}