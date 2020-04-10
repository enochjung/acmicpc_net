#include <cstdio>
#include <queue>
#define N 310

using namespace std;

struct st
{
	int x, y, p;
};

int t, l, x1, y1, x2, y2;
int dx[]={2,1,-1,-2,-2,-1,1,2}, dy[]={1,2,2,1,-1,-2,-2,-1};

int main()
{
	for(scanf("%d",&t); t--;)
	{
		bool visited[N][N] = {};
		queue<st> q;

		scanf("%d %d %d %d %d", &l, &x1, &y1, &x2, &y2);

		visited[x1][y1] = true;
		q.push({x1, y1, 0});
		while(!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int p = q.front().p;
			q.pop();

			if(x==x2 && y==y2)
			{
				printf("%d\n", p);
				break;
			}
			
			for(int w=0; w<8; ++w)
			{
				int tx = x+dx[w];
				int ty = y+dy[w];
				if(0<=tx && tx<l && 0<=ty && ty<l && !visited[tx][ty])
				{
					visited[tx][ty] = true;
					q.push({tx, ty, p+1});
				}
			}
		}
	}

	return 0;
}
