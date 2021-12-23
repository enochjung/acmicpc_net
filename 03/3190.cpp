#include <cstdio>
#include <queue>
#define N 110

using namespace std;

struct point
{
	int x, y;
};

struct change_way
{
	int t;
	bool right;
};

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, k, l, a[N][N], snake_way;
queue<point> snake;
queue<change_way> way;

int simulate()
{
	for (int t = 1;; ++t)
	{
		point head = snake.back();
		point new_head = {head.x + dx[snake_way], head.y + dy[snake_way]};
		snake.push(new_head);

		if (a[new_head.x][new_head.y] == 1)
			return t;
		if (a[new_head.x][new_head.y] != 2)
		{
			point tail = snake.front();
			a[tail.x][tail.y] = 0;
			snake.pop();
		}
		a[new_head.x][new_head.y] = 1;

		if (way.front().t == t)
		{
			bool right = way.front().right;
			way.pop();

			snake_way = (snake_way + (right ? 1 : -1) + 4) % 4;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			a[i][j] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = 0;
	a[1][1] = 1;
	snake_way = 0;
	snake.push({1, 1});

	for (int i = 0; i < k; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 2;
	}

	scanf("%d", &l);
	for (int i = 0; i < l; ++i)
	{
		int t;
		char w;

		scanf("%d %c", &t, &w);
		way.push({t, w == 'D'});
	}

	printf("%d\n", simulate());
	return 0;
}