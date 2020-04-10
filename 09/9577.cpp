#include <stdio.h>
#include <string.h>

int t, n, m;
bool e[110][110];
int q[110], v[110];

bool f(int x, int lv)
{
	v[x] = lv;

	for(int i=0; i<n; i++)
		if(e[x][i] && (q[i]==-1 || (v[q[i]]<lv && f(q[i],lv))))
		{
			q[i] = x;
			return true;
		}

	return false;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		memset(e, 0, sizeof(e));
		memset(q, -1, sizeof(q));
		memset(v, -1, sizeof(v));

		scanf("%d %d", &n, &m);
		while(m--)	
		{
			int t1, t2, s;
			scanf("%d %d %d", &t1, &t2, &s);
			while(s--)	
			{
				int a;
				scanf("%d", &a);
				for(int i=t1; i<t2; i++)
					e[i][a-1] = true;
			}
		}

		int time, cnt=0;

		for(time=0; time<100; time++)
			if(f(time, time))
				if(++cnt == n)
					break;

		printf("%d\n", time>99? -1 : time+1);
	}
	return 0;
}
