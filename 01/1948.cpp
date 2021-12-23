#include <cstdio>
#include <cstring>
#include <vector>
#define N 10001

struct edge
{
	int from, cost;
	bool answer_flag;
};

int n, m, start, end;
std::vector<edge> e[N];
int d[N];
bool visited[N];

int f(int x)
{
	if (d[x] == -1)
	{
		int max_time = 0;

		for (edge &i : e[x])
		{
			int cost = f(i.from) + i.cost;
			if (max_time < cost)
				max_time = cost;
		}

		d[x] = max_time;
	}

	return d[x];
}

void g(int x)
{
	visited[x] = true;

	for (edge &i : e[x])
		if (d[x] == d[i.from] + i.cost)
		{
			i.answer_flag = true;
			if (!visited[i.from])
				g(i.from);
		}
}

int h()
{
	int count = 0;

	for (int i=1; i<=n; ++i)
		for (edge &i : e[i])
			if (i.answer_flag == true)
				++count;

	return count;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[b].push_back({a, c});
	}
	scanf("%d %d", &start, &end);

	memset(d, -1, sizeof(d));
	d[start] = 0;

	printf("%d\n", f(end));
	g(end);
	printf("%d\n", h());
	return 0;
}