#include <cstdio>
#include <algorithm>
#define N 16
#define MAX 99999999

using namespace std;

int n, w[N][N], d[N][1<<N];

int f(int x, int flag)
{
	if (d[x][flag] == 0)
	{
		if (flag == (1<<n)-1)
			d[x][flag] = w[x][0]>0? w[x][0] : MAX;
		else
		{
			int ret = MAX;
			for (int i=1; i<n; ++i)
			{
				int i_flag = 1<<i;
				if ((flag&i_flag)==0 && w[x][i]>0)
					ret = min(ret, f(i, flag|i_flag)+w[x][i]);
			}
			d[x][flag] = ret;
		}
	}

	return d[x][flag];
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			scanf("%d", &w[i][j]);

	printf("%d\n", f(0, 1));
	return 0;
}