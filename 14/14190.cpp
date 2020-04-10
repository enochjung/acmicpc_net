#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[1030];

bool f(int x)
{
	int p = -x;
	int cnt = 0;

	for(int i=0; i<n; i++)
		if(a[i]-p >= x)
		{
			p = a[i];
			cnt++;
		}
	return cnt > n/2;
}

int main()
{
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		n = (1<<n)+1;
		for(int i=0; i<n; i++)
			scanf("%d", a+i);

		sort(a, a+n);

		int ans = 1;
		int left=1, mid, right=(a[n-1]-a[0])/(n/2);
		while(left <= right)
		{
			mid = (left+right)/2;
			if(f(mid))
			{
				ans = mid;
				left = mid+1;
			}
			else
				right = mid-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
