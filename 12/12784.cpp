#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1010

using namespace std;

struct st
{
	int to, bomb;
};

int t, n;
vector<st> e[N], in[N];
bool visited[N];

void make_path(int x)
{
	visited[x] = true;

	for(st i : in[x])
		if(!visited[i.to])
		{
			e[x].push_back(i);
			make_path(i.to);
		}
}

int cut(int x)
{
	if(e[x].empty())
		return 999999;
	int sum = 0;
	for(st i : e[x])
		sum += min(i.bomb, cut(i.to));
	return sum;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %*d", &n);
		for(int i=0; i<n-1; ++i)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			--x, --y;
			in[x].push_back({y, z});
			in[y].push_back({x, z});
		}
		make_path(0);
		printf("%d\n", n>1? cut(0) : 0);

		memset(visited, 0, sizeof(visited));
		for(int i=0; i<n; ++i)
		{
			while(!e[i].empty())
				e[i].pop_back();
			while(!in[i].empty())
				in[i].pop_back();
		}
	}
	return 0;
}
