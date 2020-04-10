#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[50010], p, b[50010];
int d[50010][3];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	scanf("%d", &p);

	int sum = 0;
	for(int i=0; i<p; i++)
		sum += a[i];
	for(int i=p; i<=n; i++)
	{
		b[i-p] = sum;
		sum -= a[i-p];
		sum += a[i];
	}

	d[0][0] = b[0];
	for(int i=1; i<=n-p; i++)
	{
		d[i][0] = max(d[i-1][0], b[i]);
		if(i-p >= 0)
		{
			d[i][1] = max(d[i-1][1], b[i]+d[i-p][0]);
			d[i][2] = max(d[i-1][2], b[i]+d[i-p][1]);
		}
	}

	printf("%d\n", d[n-p][2]);
	return 0;
}
