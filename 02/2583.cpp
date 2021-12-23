#include <cstdio>
#include <set>
#define N 110

using namespace std;

int n, m, k;
bool visited[N][N];
multiset<int> ms;
int dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};

int f(int x, int y)
{
	int cnt = 1;
	visited[x][y] = true;

	for(int w=0; w<4; ++w)
	{
		int tx = x+dx[w];
		int ty = y+dy[w];

		if(0<=tx && tx<n && 0<=ty && ty<m && !visited[tx][ty])
			cnt += f(tx, ty);
	}
	return cnt;
}

int main()
{
	scanf("%d %d %d", &m, &n, &k);
	while(k--)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i=x1; i<x2; ++i)
			for(int j=y1; j<y2; ++j)
				visited[i][j] = true;
	}

	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(!visited[i][j])
				ms.insert(f(i, j));

	printf("%d\n", (int)ms.size());
	for(int v : ms)
		printf("%d ", v);
	return 0;
}