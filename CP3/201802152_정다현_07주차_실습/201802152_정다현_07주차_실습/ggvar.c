#include <stdio.h>

float PI = 3.141592;

void pprint()
{
	printf("%10f\n", PI);
}

int main(void)
{

	float PI = 3.14;

	printf("%-10.2f\n", PI);
	pprint();

}