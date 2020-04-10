#include <cstdio>
#include <algorithm>

using namespace std;

int d, n, m, a[50010];

int f(int x)
{
	int cnt=0, p=0;

	for(int i=0; i<n; ++i)
		if(p+x <= a[i])
		{
			++cnt;
			p = a[i];
		}

	return cnt + (p+x>d? -1 : 0);
}

int main()
{
	scanf("%d %d %d", &d, &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i); 

	sort(a, a+n);

	int res = 0;
	int lo=1, hi=d;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;

		if(f(mid) >= n-m)
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
