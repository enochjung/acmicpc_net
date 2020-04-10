#include <cstdio>

int n, m;
int d[110][110];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			d[i][j] = 999;
		d[i][i] = 0;
	}
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		d[a][b] = d[b][a] = 1;
	}

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(d[i][j] > d[i][k]+d[k][j])
					d[i][j] = d[i][k]+d[k][j];

	int min=999, idx=-1;
	for(int i=0; i<n; i++)
	{
		int sum = 0;
		for(int j=0; j<n; j++)
			sum += d[i][j];
		if(sum < min)
		{
			min = sum;
			idx = i;
		}
	}
	
	printf("%d\n", idx+1);
	return 0;
}
