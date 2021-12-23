#include <cstdio>
#define N 100010

int n, m, a[N];

int f(int x)
{
	int cnt=0, sum=0;
	
	for(int i=0; i<n; ++i)
	{
		if(a[i] > x)
			return m+1;
		sum += a[i];
		if(i==n-1 || sum+a[i+1]>x)
		{
			++cnt;
			sum = 0;
		}
	}
	
	return cnt;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int lo=1, hi=1000000000;
	int res = 0;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(f(mid) <= m)
		{
			res = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}

	printf("%d", res);
	return 0;
}