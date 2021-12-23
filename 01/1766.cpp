#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#define N 32001

using namespace std;

int n, m;
int cnt[N];
priority_queue<int,vector<int>,greater<int>> pq;
vector<int> e[N];

int main()
{
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		++cnt[b];
	}

	for (int i=1; i<=n; ++i)
		if (cnt[i] == 0)
			pq.push(i);

	while (!pq.empty())
	{
		int v = pq.top();
		pq.pop();

		printf("%d ", v);
		for (int to : e[v])
			if (--cnt[to] == 0)
				pq.push(to);
	}

	return 0;
}
