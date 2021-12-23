#include <cstdio>
#include <queue>
#define N 10
#define M 10
#define D 4

struct point
{
	int x, y;

	point(int x, int y)
	: x(x), y(y) {}
	point() {}

	bool operator==(const point& p) { return x==p.x && y==p.y; }
};

struct state
{
	point red, blue;
	int time, move;
	state(point red, point blue, int time, int move)
	: red(red), blue(blue), time(time), move(move) {}
};

int n, m;
char board[N][M];
point dest[N][M][D];
std::queue<state> q;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void init_dest()
{
	for (int i=1; i<n-1; ++i)
		for (int j=1; j<m-1; ++j)
			if (board[i][j] != '#')
				for (int k=0; k<D; ++k)
				{
					int nx = i;
					int ny = j;
					while (board[nx][ny] != 'O' && board[nx+dx[k]][ny+dy[k]] != '#')
					{
						nx += dx[k];
						ny += dy[k];
					}
					dest[i][j][k] = board[nx][ny] == 'O'? point(99, 99) : point(nx, ny);
				}
}

state get_initial_state()
{
	point red, blue;

	for (int i=1; i<n-1; ++i)
		for (int j=1; j<m-1; ++j)
		{
			if (board[i][j] == 'R')
			{
				red.x = i;
				red.y = j;
			}
			if (board[i][j] == 'B')
			{
				blue.x = i;
				blue.y = j;
			}
		}
	
	return state(red, blue, 0, -1);
}

void update(state st, int way, point &red, point &blue)
{
	red = dest[st.red.x][st.red.y][way];
	blue = dest[st.blue.x][st.blue.y][way];

	if (red == blue && red.x != 99)
	{
		int x_diff = (st.red.x - st.blue.x) * dx[way];
		int y_diff = (st.red.y - st.blue.y) * dy[way];

		if (x_diff != 0)
			(x_diff < 0? red : blue).x -= dx[way];
		if (y_diff != 0)
			(y_diff < 0? red : blue).y -= dy[way];
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf(" %c", &board[i][j]);

	init_dest();

	q.push(get_initial_state());
	while (!q.empty())
	{
		state &now = q.front();
		if (now.time >= 10)
			break;

		for (int k=0; k<D; ++k)
		{
			if (k == now.move)
				continue;

			point next_red, next_blue;
			update(now, k, next_red, next_blue);

			if (next_red.x == 99 && next_blue.x != 99)
			{
				printf("%d", now.time + 1);
				return 0;
			}
			if (next_blue.x != 99)
				q.push(state(next_red, next_blue, now.time + 1, k));
		}

		q.pop();
	}
	printf("-1");

	return 0;
}