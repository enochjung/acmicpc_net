#include <cstdio>
#include <queue>

using namespace std;

int t, n, m;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		queue<pair<int,bool>> q;
		priority_queue<int> pq;

		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
		{
			int v;
			scanf("%d", &v);
			q.push({v, i==m});
			pq.push(v);
		}

		for(int i=1;; i++)
		{
			while(pq.top() != q.front().first)
			{
				q.push(q.front());
				q.pop();
			}
			if(q.front().second)
			{
				printf("%d\n", i);
				break;
			}
			pq.pop();
			q.pop();
		}
	}
	return 0;
}
