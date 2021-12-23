#include <cstdio>
#include <algorithm>
#define N 1000010

using namespace std;

int n, c, a[N];

long long f(int x)
{
	int p = a[0];
	int cnt = 1;
	
	for(int i=1; i<n; ++i)
		if(a[i] >= p+x)
		{
			p = a[i];
			++cnt;
		}
	
	return cnt;
}

int main()
{
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	int lo=0, hi=1000000000;
	int res = 0;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(f(mid) >= c)
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