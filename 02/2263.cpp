#include <cstdio>
#define N 100001

int n, b[N], c[N];

void f(int bs, int cs, int len)
{
	if (len <= 0)
		return;

	int root = c[cs+len-1];
	int llen = b[root]-bs;
	int rlen = len-llen-1;

	printf("%d ", root);

	f(bs, cs, llen);
	f(b[root]+1, cs+llen, rlen);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		int val;
		scanf("%d", &val);
		b[val] = i;
	}
	for (int i=1; i<=n; ++i)
		scanf("%d", c+i);

	f(1, 1, n);
	return 0;
}