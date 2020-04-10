#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[310];
int d[310][2];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d", a+i);

	d[1][0] = a[1];
	for(int i=2; i<=n; ++i)
	{
		d[i][0] = max(d[i-2][0],d[i-2][1])+a[i];
		d[i][1] = d[i-1][0]+a[i];
	}
	

	printf("%d", max(d[n][0], d[n][1]));
	return 0;
}
