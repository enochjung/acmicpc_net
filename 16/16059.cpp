#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300000

using namespace std;

int n, m, a[N], d[N];

int f(int x)
{
	if (x >= n)
		return 0;
	if (d[x] == -1)
		d[x] = max(a[x]+f(x+m), f(x+1));

	return d[x];
}

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	printf("%d\n", f(m));
	return 0;
}