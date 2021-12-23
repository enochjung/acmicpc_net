#include <cstdio>
#define N 100001
#define T (1<<17)
#define TT (1<<18)
#define MAX 1999999999

int n, m, a[N], t[TT];

void update(int i)
{
	for (i=(i-1+T)>>1; i>=1; i>>=1)
	{
		int li = t[i*2];
		int ri = t[i*2+1];
		t[i] = a[li]<=a[ri]? li : ri;
	}
}

int get(int i, int s, int e, int p, int q)
{
	if (q<=s || e<=p)
		return 0;
	if (s<=p && q<=e)
		return t[i];

	int m = (p+q)/2;
	int li = get(i*2, s, e, p, m);
	int ri = get(i*2+1, s, e, m, q);
	return a[li]<=a[ri]? li : ri;
}

int main()
{
	scanf("%d", &n);
	a[0] = MAX;
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", a+i);
		t[i-1+T] = i;
	}
	for (int i=1; i<=n; ++i)
		update(i);

	scanf("%d", &m);
	while (m--)
	{
		int q, i, j;
		scanf("%d %d %d", &q, &i, &j);

		if (q == 1)
		{
			a[i] = j;
			update(i);
		}
		else
			printf("%d\n", get(1, i, j+1, 1, T+1));
	}
	return 0;
}