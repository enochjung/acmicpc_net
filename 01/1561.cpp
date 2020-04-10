#include <cstdio>

int n, m, a[10010];

long long f(long long x)
{
	long long cnt = 0;
	for(int i=0; i<m; ++i)
		cnt += x/a[i];
	return cnt;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
		scanf("%d", a+i);

	long long left=0, right=99999999999, time, rest;
	while(left <= right)
	{
		long long mid = (left+right)/2;
		long long v = f(mid)-n+m;
		if(v >= 0)
		{
			time = mid;
			rest = v;
			right= mid-1;
		}
		else
			left = mid+1;
	}

	for(int i=m-1; i>=0; --i)
		if(time%a[i] == 0)
			if(rest-- == 0)
			{
				printf("%d", i+1);
				break;
			}
	return 0;
}
