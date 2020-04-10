#include <cstdio>

int n, m;
char s[110];

bool f(char c[])
{
	int i=0, j=0;
	for(; c[j]; ++j)
	{
		if(s[i] == c[j])
			++i;
		if(i == n)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d %d %s", &n, &m, s);
	
	while(m--)
	{
		char c[1010];
		scanf("%s", c);
		printf("%s\n", f(c)? "true" : "false");
	}

	return 0;
}
