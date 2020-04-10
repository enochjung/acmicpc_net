#include <cstdio>

char s[110];

int main()
{
	scanf("%s", s);

	for(int i=0; s[i]; i++)
	{
		printf("%c", s[i]);
		if(i%10 == 9)
			printf("\n");
	}
	return 0;
}
