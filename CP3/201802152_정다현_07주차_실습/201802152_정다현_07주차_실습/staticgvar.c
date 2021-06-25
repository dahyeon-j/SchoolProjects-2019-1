#include <stdio.h>

static int svar;

int gvar;

void increment();
void testglobal();

int main(void)
{
	for (int count = 1; count <= 5; count++)
		increment();
	printf("함수 increment가 총 %d번 호출되었습니다.\n", svar);

	testglobal();
	printf("전역변수: %d\n", gvar);
	//teststatic();
}

void increment()
{
	svar++;
}