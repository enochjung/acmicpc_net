#include <cstdio>
#include <algorithm>
#define N 100010

using namespace std;

int n, m, a[N];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	res = a[n-1]-a[0];
	for(int i=0,j=1; j<n;)
	{
		if(a[j]-a[i]>=m)
			res = min(res, a[j]-a[i]);

		if(a[j]-a[i] < m)
			++j;
		else
			++i;
	}

	printf("%d", res);
	return 0;
}