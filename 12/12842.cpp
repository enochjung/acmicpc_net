#include <cstdio>

int n, s, m, a[100010];

long long f(int x)
{
	long long cnt = 0;
	for(int i=0; i<m; ++i)
		cnt += x/a[i];
	return cnt;
}

int main()
{
	scanf("%d %d %d", &n, &s, &m);
	for(int i=0; i<m; ++i)
		scanf("%d", a+i);

	n -= s;
	int left=0, right=100000000, time, rest;
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
