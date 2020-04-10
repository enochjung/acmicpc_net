#include <cstdio>

int t, n, a[1010];
double avg;
int cnt;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		avg = 0;
		cnt = 0;

		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", a+i);
			avg += a[i];
		}
		avg /= n;

		for(int i=0; i<n; i++)
			if(a[i] > avg)
				cnt++;
		printf("%.3lf%%\n", (double)cnt/n*100);
	}
	return 0;
}
