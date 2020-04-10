#include <cstdio>

int t;
long long n;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%lld", &n);

		int left=1, right=2e8, res;
		while(left <= right)
		{
			int mid = (left+right)/2;
			if(1LL*mid*(mid+1)/2 <= n)
			{
				res = mid;
				left = mid+1;
			}
			else
				right = mid-1;
		}
		printf("%d\n", res);
	}
	return 0;
}
