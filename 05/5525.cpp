#include <cstdio>
#define M 1000001

int n, m;
char s[M];

int main()
{
	scanf("%d %d %s", &n, &m, s);

	int res = 0;
	int type = 0;
	for (int i=0; i<m; ++i)
	{
		if (s[i] == 'I')
			type = type&1? 1 : type+1;
		else
			type = type&1? type+1 : 0;
		if (type >= n*2+1 && type%2)
			++res;
	}

	printf("%d\n", res);
	return 0;
}