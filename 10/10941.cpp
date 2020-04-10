#include <cstdio>

char s[60];

int v(char c)
{
	if(c >= 'a')
		return c-'a'+10;
	if(c >= 'A')
		return c-'A'+10;
	return c-'0';
}

int main()
{
	scanf("%s", s);
	
	for(int i=0; s[i]; i+=2)
		printf("%c", v(s[i])*16+v(s[i+1]));
	printf("\n");
	return 0;
}
