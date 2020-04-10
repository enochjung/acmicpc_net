#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 1000

using namespace std;

int t, k, n;
int a[4][N], b[2][N*N];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &k, &n);
		for(int i=0; i<4; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &a[i][j]);

		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				b[0][i*n+j] = a[0][i]+a[1][j];
				b[1][i*n+j] = a[2][i]+a[3][j];
			}

		sort(b[0], b[0]+n*n);

		int res = 99999999;
		for(int i=0; i<n*n; ++i)
		{
			int idx = (int)(lower_bound(b[0], b[0]+n*n, k-b[1][i]) - b[0]);
			if(abs(k-res)>abs(k-b[0][idx]-b[1][i]) || (abs(k-res)==abs(k-b[0][idx]-b[1][i]) && res>b[0][idx]+b[1][i]))
				res = b[0][idx]+b[1][i];
			if(idx>0 && (abs(k-res)>abs(k-b[0][idx-1]-b[1][i]) || (abs(k-res)==abs(k-b[0][idx-1]-b[1][i]) && res>b[0][idx-1]+b[1][i])))
				res = b[0][idx-1]+b[1][i];
		}

		printf("%d\n", res);
	}

	return 0;
}
