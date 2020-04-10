#include <cstdio>
#include <cstring>
#define N 500010

char s[N];
int n, a, b;
int l[N], p[N];

int f(int w)
{
	int x = 0;
	int ret = 0;

	while(x < n)
	{
		ret += l[x];
		x = x+w<n? p[x+w] : n;
	}

	return ret-1;
}

int main()
{
	scanf("%[^\n] %d %d", s, &a, &b);
	n = (int)strlen(s);
	s[n++] = ' ';

	int x = 0;
	for(int i=0; s[i]; ++i)
	{
		p[i] = x;
		if(s[i] == ' ')
		{
			l[x] = i-x+1;
			x = i+1;
		}
	}

	for(int i=a; i<=b; ++i)
		printf("%d\n", f(i+1));
	return 0;
}
