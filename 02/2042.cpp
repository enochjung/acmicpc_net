#include <cstdio>
#define N 1000001

int n, m, k;
long long t[N];

long long sum(int idx)
{
	long long res = 0;
	while (idx)
	{
		res += t[idx];
		idx -= idx&(-idx);
	}
	return res;
}

void update(int idx, long long val)
{
	long long delta = val-(sum(idx)-sum(idx-1));
	while (idx <= n)
	{
		t[idx] += delta;
		idx += idx&(-idx);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=n; ++i)
	{
		long long v;
		scanf("%lld", &v);
		update(i, v);
	}
	for (int i=0; i<m+k; ++i)
	{
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a == 1)
			update(b, c);
		else
			printf("%lld\n", sum(c)-sum(b-1));
	} 
	
	return 0;
}
