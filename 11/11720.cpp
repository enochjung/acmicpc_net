#include <cstdio>

int n, res;
char s[110];

int main()
{
	scanf("%d %s", &n, s);
	
	for(int i=0; i<n; i++)
		res += s[i]-'0';

	printf("%d\n", res);
	return 0;
}
