#include <cstdio>

char s[20];
int res;

int main()
{
	scanf("%s", s);
	for(int i=0; s[i]; i++)
		res += (s[i]>'R'? (s[i]=='Z'? s[i]-'C' : s[i]-'B') : s[i]-'A')/3+3;
	printf("%d\n", res);
	return 0;
}
