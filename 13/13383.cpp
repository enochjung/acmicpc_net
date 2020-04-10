#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int t, n, m;

int main()
{
	freopen("input.txt", "r", stdin);
	for(scanf("%d",&t); t--;)
	{
		bool p[110]={}, visited[110]={};
		vector<int> v[110];
		queue<int> q;

		int f=-1, cnt=0;

		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);

			if(f == -1)
				f = x;
			p[x] ^= z&1;
			p[y] ^= z&1;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		cnt = n;
		for(int i=0; i<n; i++)
			if(v[i].empty())
				cnt--;

		int num1=1, num2=0;

		visited[f] = true;
		q.push(f);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			
			int size = (int)v[x].size();
			for(int i=0; i<size; i++)
			{
				int to = v[x][i];

				if(!visited[to])
				{
					q.push(to);
					visited[to] = true;
					num1++;
				}
			}
		}

		for(int i=0; i<n; i++)
			if(p[i])
				num2++;

		printf("%s\n", num1<cnt || num2 > 2? "no" : "yes");
	}
	return 0;
}
