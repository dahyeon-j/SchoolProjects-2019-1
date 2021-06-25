#include <stdio.h>
#include <string.h>

int main(void)
{
	char studentsName[5][20];
	
	for (int i = 0; i < 5; i++) {
		printf("input students name[%d] : ", i);
		scanf_s("%s", studentsName[i], 19); // 배열은 주소값
	}

	printf("input complete\n");

	int flag = 0;

	char c[20];
	printf("search for name : ");
	scanf_s("%s", c, 19);

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(c, studentsName[i]) == 0)
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		printf("found it!");
	}
	else
	{
		printf("nope");
	}

	return 0;
}