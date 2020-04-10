#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[100010];
int res;

int abs(int x)
{
	return x>0? x : -x;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	sort(a, a+n);

	for(int i=2; i<n; i++)
	{
		int v = abs(a[0]+a[i]-a[i-1]*2);
		if(res < v)
			res = v;
	}
	for(int i=1; i<n-1; i++)
	{
		int v = abs(a[n-1]+a[i-1]-a[i]*2);
		if(res < v)
			res = v;
	}

	printf("%d\n", res);
	return 0;
}
