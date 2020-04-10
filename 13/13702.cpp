#include <cstdio>
#include <limits>

int n, k, a[10010];

bool f(int x)
{
	int sum = 0;
	for(int i=0; i<n; ++i)
		sum += a[i]/x;
	return sum >= k;
}

int main()
{
	int low = 0;
	int high = std::numeric_limits<int>::max();

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	for(int w=0; w<100; w++)
	{
		int mid = (low+high)/2;

		if(f(mid))
			low = mid;
		else
			high = mid;
	}

	printf("%d", low);
	return 0;
}
