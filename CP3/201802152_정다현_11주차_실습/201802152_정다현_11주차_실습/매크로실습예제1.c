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
	printf("%d\n", SQUARE(++x)); // ++x 가 전처리 기에 들어가면서 ++가 2번 된다. 4 * 4가 됨

	return 0;
}