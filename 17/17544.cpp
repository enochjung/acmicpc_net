#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define N 1010
#define MAX 1000000000

using namespace std;

int r, c, k, a[N][N];
bool v[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

struct st
{
	int x, y;
};

bool f(int val)
{
	vector<queue<st>> q(N);

	memset(v, 0, sizeof(v));
	q[0].push({0, 0});
	v[0][0] = true;

	for (int cost = 0; cost <= k; ++cost)
	{
		while (!q[cost].empty())
		{
			st now = q[cost].front();
			q[cost].pop();
			int x = now.x;
			int y = now.y;

			if (x == r + 1)
				return true;

			for (int w = 0; w < 4; ++w)
			{
				int tx = x + dx[w];
				int ty = y + dy[w];
				if (0 <= tx && tx < r + 2 && 0 <= ty && ty < c && !v[tx][ty])
				{
					if (a[tx][ty] >= val)
						q[cost].push({tx, ty});
					else
						q[cost + 1].push({tx, ty});
					v[tx][ty] = true;
				}
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= r; ++i)
		for (int j = 0; j < c; ++j)
			scanf("%d", &a[i][j]);
	for (int j = 0; j < c; ++j)
		a[0][j] = a[r + 1][j] = MAX;

	int low = 0;
	int high = MAX;
	int res = 0;

	while (low <= high)
	{
		int min = (low + high) / 2;
		if (f(min))
		{
			low = min + 1;
			res = min;
		}
		else
			high = min - 1;
	}

	printf("%d\n", res);
	return 0;
}