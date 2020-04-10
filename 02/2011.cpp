#include <cstdio>
#include <cstring>
#define N 5010
#define R 1000000

int d[N];
char s[N];

int f(int x)
{
	if(s[x] == 0)
		return 1;
	if(d[x] == -1)
	{
		d[x] = 0;
		if(s[x] != '0')
			d[x] += f(x+1);
		if((s[x]=='1' && s[x+1]!=0) || (s[x]=='2' && '0'<=s[x+1] && s[x+1]<='6'))
			d[x] += f(x+2);
		d[x] %= R;
	}

	return d[x];
}

int main()
{
	scanf("%s", s);
	memset(d, -1, sizeof(d));
	printf("%d", f(0));
	return 0;
}
