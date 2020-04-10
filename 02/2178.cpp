#include <cstdio>
#include <queue>

using namespace std;

struct st
{
	int x, y, t;
};

const int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

int n, m;
char a[110][110];
bool v[110][110];
queue<st> q;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%s", a[i]);

	q.push({0, 0, 1});
	v[0][0] = true;
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int t = q.front().t;
		q.pop();

		if(x == n-1 && y == m-1)
		{
			printf("%d\n", t);
			break;
		}

		for(int k=0; k<4; k++)
		{
			int nx = x+dx[k];
			int ny = y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m && a[nx][ny]=='1' && !v[nx][ny])
			{
				q.push({nx, ny, t+1});
				v[nx][ny] = true;
			}
		}
	}

	return 0;
}
