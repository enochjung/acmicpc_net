#include <cstdio>
#define N 1000010

int n, m, a[N];

long long f(int x)
{
	long long sum = 0;
	
	for(int i=0; i<n; ++i)
		if(a[i] > x)
			sum += a[i]-x;
	
	return sum;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int lo=0, hi=1000000000;
	int res = 0;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(f(mid) >= m)
		{
			res = mid;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}

	printf("%d", res);
	return 0;
}