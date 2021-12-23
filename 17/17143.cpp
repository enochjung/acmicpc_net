#include <cstdio>
#include <cstring>
#define N 100

struct shark
{
	int size, speed, way;
};

int r, c, m;
shark s[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int get(int y)
{
	for (int i=0; i<r; ++i)
		if (s[i][y].size > 0)
		{
			int ret = s[i][y].size;
			s[i][y] = {0, 0, 0};
			return ret;
		}
	return 0;
}

void update(shark a[N][N], int x, int y, shark s)
{
	if (a[x][y].size < s.size)
		a[x][y] = s;
}

void move(int &x, int &y, int &way, int speed)
{
	while (speed > 0)
	{
		int m = way<2? r : c;
		int dp = way<2? dx[way] : dy[way];
		int &p = way<2? x : y;

		speed %= m*2-2;
		int d = (dp*(m-1)+m-1)/2;
		if (speed >= -dp*p + d)
		{
			speed -= -dp*p + d;
			p = d;
			way = way<2? 1-way : 3-way+2;
		}
		else
		{
			p += speed*dp;
			speed = 0;
		}
	}
}

void move_all()
{
	shark t[N][N];

	memset(t, 0, sizeof(t));
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			if (s[i][j].size > 0)
			{
				int x=i, y=j;
				int size = s[i][j].size;
				int speed = s[i][j].speed;
				int way = s[i][j].way;

				move(x, y, way, speed);
				update(t, x, y, {size, speed, way});
			}

	memcpy(s, t, sizeof(s));
}

int main()
{
	scanf("%d %d %d", &r, &c, &m);
	while (m--)
	{
		int x, y, speed, way, size;
		scanf("%d %d %d %d %d", &x, &y, &speed, &way, &size);
		s[x-1][y-1] = {size, speed, way-1};
	}

	int res = 0;
	for (int j=0; j<c; ++j)
	{
		res += get(j);
		move_all();
	}

	printf("%d\n", res);
	return 0;
}