#include <cstdio>
#include <climits>
#define K 10000

int k, n, a[K];

bool f(long long x)
{
	long long sum = 0;
	
	for (int i=0; i<k; ++i)
		sum += a[i]/x;
	
	return sum >= n;
}

int main()
{
	scanf("%d %d", &k, &n);
	for (int i=0; i<k; ++i)
		scanf("%d", a+i);

	long long low=1, high=INT_MAX;
	int res = 0;
	while (low <= high)
	{
		long long mid = (low+high)/2;
		if (f(mid))
		{
			res = mid;
			low = mid+1;
		}
		else
			high = mid-1;
	}

	printf("%d\n", res);
	return 0;
}