#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
queue<int> q;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		q.push(i);

	while(m--)
	{
		int v;
		scanf("%d", &v);

		int cnt = 0;
		for(; v!=q.front(); cnt++)
		{
			q.push(q.front());
			q.pop();
		}
		res += min(cnt, (int)q.size()-cnt);

		q.pop();
	}
	printf("%d\n", res);
	return 0;
}
