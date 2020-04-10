#include <cstdio>
#include <queue>
#define N 130

using namespace std;

int n, a[N][N];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

struct st
{
	int x, y, c;
	bool operator<(const st &i) const
	{
		return c > i.c;
	}
};

int main()
{
	for(int t=1;; ++t)
	{
		scanf("%d", &n);
		if(n == 0)
			break;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &a[i][j]);

		int d[N][N];
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				d[i][j] = 9999;

		priority_queue<st> q;
		q.push({0, 0, a[0][0]});
		while(!q.empty())
		{
			st now = q.top();
			int x=now.x, y=now.y, c=now.c;
			q.pop();

			if(d[x][y] > c)
			{
				d[x][y] = c;
				for(int i=0; i<4; ++i)
				{
					int px = x+dx[i];
					int py = y+dy[i];
					if(0<=px && px<n && 0<=py && py<n && d[px][py]>c+a[px][py])
						q.push({px, py, c+a[px][py]});
				}
			}
		}
		printf("Problem %d: %d\n", t, d[n-1][n-1]);
	}
	return 0;
}
