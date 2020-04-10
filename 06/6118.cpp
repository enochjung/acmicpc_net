#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define N 20010

using namespace std;

int n, m;
int d[N];
vector<int> e[N];
queue<int> q;

int main()
{
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	memset(d, -1, sizeof(d));
	d[1] = 0;
	q.push(1);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		for(int to : e[now])
			if(d[to] == -1)
			{
				d[to] = d[now]+1;
				q.push(to);
			}
	}
	
	int num=1, dis=0, cnt=1;
	for(int i=2; i<=n; ++i)
	{
		if(dis == d[i])
			cnt++;
		else if(dis < d[i])
		{
			num = i;
			dis = d[i];
			cnt = 1;
		}
	}

	printf("%d %d %d", num, dis, cnt);
	return 0;
}
