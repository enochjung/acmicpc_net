#include <cstdio>

char s[110];

int main()
{
	scanf("%s", s);

	for(int i=0; s[i]; ++i)
		if('A'<=s[i] && s[i]<='Z')
			printf("%c", s[i]);

	return 0;
}
