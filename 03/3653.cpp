#include <cstdio>
#include <cstring>
#define N 100010

int t, n, m, a[N];
int v[N*2];

void add(int idx, int val)
{
	while(idx <= n+m)
	{
		v[idx] += val;
		idx += idx&-idx;
	}
}

int get(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += v[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		memset(v, 0, sizeof(v));

		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; ++i)
		{
			add(i, 1);
			a[i] = n+1-i;
		}

		for(int i=n+1; i<=n+m; ++i)
		{
			int k;
			scanf("%d", &k);
			printf("%d ", get(n+m)-get(a[k]));
			add(a[k], -1);
			a[k] = i;
			add(a[k], 1);
		}
		printf("\n");
	}

	return 0;
}
