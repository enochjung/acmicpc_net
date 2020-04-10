#include <cstdio>
#define N 500010

int n, a[N*2], b[N], t[N];

void add(int idx)
{
	while(idx <= n)
	{
		++t[idx];
		idx += idx&-idx;
	}
}

int get(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += t[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a[v] = i;
	}
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		b[a[v]] = i+1;
	}

	long long res = 0;
	for(int i=0; i<n; ++i)
	{
		res += get(n)-get(b[i]);
		add(b[i]);
	}
	printf("%lld", res);
	return 0;
}
