#include <stdio.h>

void toUpperCase(char* src, char* dst) {
	
	while (*src)
	{
		if (*src <= 'z' && 'a' <= *src)
		{
			*dst = *src - 32;
		}
		else
		{
			*dst = *src;
		}
		src++;
		dst++;
	}
	*dst = '\0';
}

void subString(char* src, char* dst, int start, int end) {
	for (int i = start; i < end; i++)
	{
		*dst = *(src + i);
		dst++;
	}
	*dst = '\0';
}

int main(void)
{
	char s1[10] = "stRIng";
	char s2[10];
	char s3[10] = "subString";
	char s4[10];
	toUpperCase(s1, s2);
	subString(s3, s4, 2, 5);
	printf("toUpperCase    : %s -> %s\n", s1, s2);
	printf("subString      : %s , 2, 5 -> %s\n", s3, s4);

	return 0;
}