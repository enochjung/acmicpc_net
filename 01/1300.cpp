#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;

int f(int x)
{
	int sum = 0;

	for(int i=1; i<=n; i++)
		sum += min(x/i, n);
	
	return sum;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	int left = 1;
	int right = k;
	while(left < right)
	{
		int mid = (left+right)/2;

		if(f(mid) < k)
			left = mid+1;
		else
			right = mid;
	}

	printf("%d", left);
	return 0;
}
