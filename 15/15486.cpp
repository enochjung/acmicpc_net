#include <cstdio>
#include <algorithm>
#define N 1500010

using std::max;

int n, t[N], p[N];
int d[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", t+i, p+i);

	for(int i=0; i<n; i++)
	{
		d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
		d[i+1] = max(d[i+1], d[i]);
	}

	printf("%d", d[n]);
	return 0;
}

