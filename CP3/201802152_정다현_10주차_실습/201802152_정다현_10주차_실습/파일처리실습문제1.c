#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char fname[] = "갸아악.txt";
	FILE *f;

	if ((f = fopen(fname, "ab+")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	
	char line[80] = {0,};

	fgets(line, sizeof(line), stdin);

	while ( !feof(stdin) )
	{
		fputs(line, f);
		fgets(line, 80, stdin);

		/*scanf_s("%s", line, sizeof(line));
		//fwrite(line, sizeof(line), 1, f);
		fprintf(f, "%s", line);
		fgets()
		*/
	}

	fclose(f);

	return 0;
}