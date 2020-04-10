#include <stdio.h>

int n, a[30];
int d[30][30];

int dis(int x, int y)
{
	return a[x]>a[y]?a[x]-a[y]:a[y]-a[x];
}

int main()
{
	scanf("%*d %d %d %d", a, a+1, &n);
	n += 2;
	for(int i=2; i<n; i++)
		scanf("%d", a+i);
	
	for(int i=2; i<n; i++)
	{
		d[i][i-1] = 9999;
		for(int j=0; j<i-1; j++)
			if(d[i][i-1] > d[i-1][j]+dis(i,j))
				d[i][i-1] = d[i-1][j]+dis(i,j);
		for(int j=0; j<i-1; j++)
			d[i][j] = d[i-1][j]+dis(i,i-1);
	}

	int res = 9999;
	for(int i=0; i<n-1; i++)
		if(res > d[n-1][i])
			res = d[n-1][i];
	printf("%d\n", res);
	return 0;
}
