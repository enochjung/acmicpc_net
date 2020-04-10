#include <stdio.h>
#include <algorithm>
#define N 4010

using namespace std;

int n, a[N], b[N], c[N], d[N]; 
int e[16000010];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d %d %d", a+i, b+i, c+i, d+i);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			e[i*n+j] = a[i]+b[j];

	sort(e, e+n*n);

	long long res = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			int num = -c[i]-d[j];
			int u = (int)(upper_bound(e, e+n*n, num) - e);
			int l = (int)(lower_bound(e, e+n*n, num) - e);
			res += u-l;
		}

	printf("%lld", res);
	return 0;
}
