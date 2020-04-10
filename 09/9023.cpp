#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110

using namespace std;

int t, c, d, dd;
int n, m, a[N], b[N], dp[N][N][3];

void update(int i, int j, int r, int val)
{
	if(dp[i][j][r] == -1)
		dp[i][j][r] = val;
	dp[i][j][r] = min(dp[i][j][r], val);
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d %d", &c, &d, &dd);
		for(n=0; scanf("%d",a+n), a[n]; ++n);
		for(m=0; scanf("%d",b+m), b[m]; ++m);

		memset(dp, -1, sizeof(dp));
		dp[0][0][0] = 0;

		for(int i=0; i<=n; ++i)
			for(int j=0; j<=m; ++j)
				for(int r=0; r<3; ++r)
					if(dp[i][j][r] != -1)
					{
						if(i<n && j<m)
							update(i+1, j+1, 0, dp[i][j][r]+(a[i]==b[j]? c : c*2));
						if(i < n)
							update(i+1, j, 2, dp[i][j][r]+c+(r==2? 0 : d)+dd);
						if(j < m)
							update(i, j+1, 1, dp[i][j][r]+c+(r==1? 0 : d)+dd);
					}

		int res = 9999;
		for(int r=0; r<3; ++r)
			if(dp[n][m][r] != -1)
				res = min(res, dp[n][m][r]);
		printf("%d\n", res);
	}

	return 0;
}
