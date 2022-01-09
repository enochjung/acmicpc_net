#include <cstdio>
#define N 10000

int n, a[N];

int find(int s, int e, int v)
{
	if (s == e)
		return s;

	int m = (s+e)/2;
	if (a[m] < v)
		return find(m+1, e, v);
	else
		return find(s, m, v);
}

void f(int s, int e)
{
	if (s >= e)
		return;
	if (s+1 == e)
	{
		printf("%d\n", a[s]);
		return;
	}

	int root = a[s];
	int idx = find(s+1, e, root);

	f(s+1, idx);
	f(idx, e);
	printf("%d\n", root);
}

int main()
{
	for (; scanf("%d",&a[n])!=EOF; ++n);

	f(0, n);

	return 0;
}