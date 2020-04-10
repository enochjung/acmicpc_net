#include <cstdio>

int n, m, k;
long long t[1000010];

void update(int idx, int val)
{
	while(idx <= n)
	{
		t[idx] += val;
		idx += idx&(-idx);
	}
}

long long get(int idx)
{
	long long sum = 0;

	while(idx)
	{
		sum += t[idx];
		idx -= idx&(-idx);
	}

	return sum;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; ++i)
	{
		int v;
		scanf("%d", &v);
		update(i, v);
	}
	for(int i=0; i<m+k; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1)
		{
			int v = get(b)-get(b-1);
			update(b, c-v);
		}
		else
			printf("%lld\n", get(c)-get(b-1));
	} 
	
	return 0;
}
