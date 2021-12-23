#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 20

using namespace std;

int t, n, x[N], y[N];

int sum(int *arr, int *cond, int val)
{
	int ret = 0;

	for (int i=0; i<n; ++i)
		if (cond[i] == val)
			ret += arr[i];
	
	return ret;
}

double f(int a[N])
{
	int xa=sum(x,a,0), xb=sum(x,a,1);
	int ya=sum(y,a,0), yb=sum(y,a,1);

	return sqrt(1LL*(xa-xb)*(xa-xb) + 1LL*(ya-yb)*(ya-yb));
}

int main()
{
	for (scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d %d", x+i, y+i);

		int a[N] = {};
		for (int i=n/2; i<n; ++i)
			a[i] = 1;

		double res = f(a);
		while (next_permutation(a+1, a+n))
			res = min(res, f(a));

		printf("%.10lf\n", res);
	}

	return 0;
}