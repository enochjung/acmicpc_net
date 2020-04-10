#include <cstdio>
#include <cstring>
#include <vector>
#define N 10010

using namespace std;

int n;
int d[N][3];
vector<int> e[N];

int f(int x, int t, int p)
{
	if(d[x][t] == -1)
	{
		int sum = 0;
		if(t == 0)
		{
			d[x][t] = f(x, 1, p);
			for(int to : e[x])
			{
				if(to == p)
					continue;
				sum += f(to, 0, x);
			}
			for(int to : e[x])
			{
				if(to == p)
					continue;
				d[x][t] = min(d[x][t], sum-f(to,0,x)+f(to,1,x));
			}
		}
		else
		{
			if(t == 1)
				++sum;
			for(int to : e[x])
			{
				if(to == p)
					continue;
				sum += f(to, t==1? 2 : 0, x);
			}
			d[x][t] = t==1? sum : min(sum, f(x,1,p));
		}
	}

	return d[x][t];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n-1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	memset(d, -1, sizeof(d));
	printf("%d", f(0, 0, -1));
	return 0;
}