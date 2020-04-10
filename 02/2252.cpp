#include <cstdio>
#include <queue>
#include <vector>
#define N 32010

using namespace std;

int n, m, c[N];
queue<int> q;
vector<int> e[N];

int main()
{
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		e[a].push_back(b);
		++c[b];
	}
	for(int i=0; i<n; ++i)
		if(c[i] == 0)
			q.push(i);

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		printf("%d ", now+1);
		for(int to : e[now])
		{
			--c[to];
			if(c[to] == 0)
				q.push(to);
		}
	}

	return 0;
}
