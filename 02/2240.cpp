#include <stdio.h>
#include <algorithm>

using namespace std;

int n, w, a[1010];
int d[1010][10][40];

int main()
{
	scanf("%d %d", &n, &w);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=2; j++)
			for(int k=0; k<=w; k++)
			{
				if(j==2 && k==0)
					continue;
				d[i][j][k] = max(d[i-1][j][k], k>0?d[i-1][3-j][k-1]:0); 
				d[i][j][k] += a[i-1]==j;
			}

	int res = 0;
	for(int j=1; j<=2; j++)
		for(int k=0; k<=w; k++)
			res = max(res, d[n][j][k]);
	printf("%d\n", res);
	return 0;
}
