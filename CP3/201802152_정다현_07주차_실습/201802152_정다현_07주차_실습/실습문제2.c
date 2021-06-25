#include <stdio.h>

void toUpperCase(char* src)
{
	while (*src) {

		if (*src <= 'z' && 'a' <= *src)
		{
			*src = *src - 32;
	
		}
		src++;
	}
}


int main(void)
{
	char s1[5] = "abCd";
	toUpperCase(s1);
	printf("%s", s1);

	return 0;
}