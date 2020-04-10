#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n;
double a[1010], d[1010];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%lf", a+i);
	
		for(int i=0; i<n; i++)
		{
			double m = 0;
			for(int j=i-5; j<=i-3; j++)
				if(j >= 0)
					m = max(m, d[j]);
			d[i] = m+a[i];
		}
	
		printf("%.1lf\n", max(d[n-1], max(d[n-2], d[n-3])));
	}
	return 0;
}
