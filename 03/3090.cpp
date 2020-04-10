#include <cstdio>
#define N 100010
#define MAX 999999999

using namespace std;

int n, t, a[N], b[N];

bool f(int x)
{
	long long cnt = 0;

	for(int i=0; i<n; ++i)
		b[i] = a[i];

	for(int i=n-1; i>0; --i)
		if(b[i-1] > b[i]+x)
		{
			cnt += b[i-1]-b[i]-x;
			b[i-1] = b[i]+x;
		}
	for(int i=0; i<n-1; ++i)
		if(b[i+1] > b[i]+x)
		{
			cnt += b[i+1]-b[i]-x;
			b[i+1] = b[i]+x;
		}
	
	return cnt <= t;
}

int main()
{
	scanf("%d %d", &n, &t);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int res = MAX;
	int lo=0, hi=MAX;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(f(mid))
		{
			res = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	f(res);
	for(int i=0; i<n; ++i)
		printf("%d ", b[i]);
	return 0;
}
