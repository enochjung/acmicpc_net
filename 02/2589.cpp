#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int px[4]={-1,0,1,0}, py[4]={0,-1,0,1};
int n, m;
char a[60][60];

int f(int x, int y)
{
	int ret = 1;
	int c[60][60] = {};
	queue<pair<int,int>> q;
	
	q.push({x, y});
	c[x][y] = 1;
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++)
		{
			int dx = x+px[i];
			int dy = y+py[i];
			if(0<=dx && dx<n && 0<=dy && dy<m && a[dx][dy]=='L' && c[dx][dy]==0)
			{
				c[dx][dy] = c[x][y]+1;
				q.push({dx, dy});
			}
		}

		ret = max(ret, c[x][y]);
	}

	return ret-1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%s", a[i]);

	int res = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j] == 'L')
				res = max(res, f(i, j));

	printf("%d", res);
	return 0;
}
