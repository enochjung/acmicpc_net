#include <cstdio>
#include <cstring>
#define R 1000007

int n, m, c;
int a[60][60], d[60][60][60][60];

int f(int x, int y, int k, int w)
{
	if(x==-1 || y==-1)
		return 0;
	if(k==0 && w>0)
		return 0;
	if(k > w)
		return 0;

	if(d[x][y][k][w] == -1)
	{
		if(a[x][y])
		{
			int sum = 0;
			if(a[x][y] == w)
				for(int i=k-1; i<w; i++)
					sum += f(x-1,y,k-1,i) + f(x,y-1,k-1,i);
			d[x][y][k][w] = sum % R;
		}
		else
			d[x][y][k][w] = (f(x-1,y,k,w)+f(x,y-1,k,w)) % R;
	}

	return d[x][y][k][w];
}

int main()
{
	scanf("%d %d %d", &n, &m, &c);
	for(int i=1; i<=c; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		a[p-1][q-1] = i;
	}

	memset(d, -1, sizeof(d));
	d[0][0][a[0][0]>0][a[0][0]] = 1;

	for(int k=0; k<=c; k++)
	{
		int sum = 0;
		for(int w=k; w<=c; w++)
			sum = (sum+f(n-1,m-1,k,w)) % R;
		printf("%d ", sum);
	}
	return 0;
}
