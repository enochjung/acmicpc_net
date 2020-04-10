#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[20];

int main()
{
	scanf("%s", s);
	printf("%d", strchr(s,'x')==nullptr? 0 : s[0]=='x'? 1 : s[0]=='-' && s[1]=='x'? -1 : atoi(s));
	return 0;
}
