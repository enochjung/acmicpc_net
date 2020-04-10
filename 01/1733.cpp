#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n;
int p[1000010], q[1000010], v[1000010];
vector<int> e[1000010];


bool f(int x, int lv)
{
	v[x] = lv;

	for(int y : e[x])
		if(q[y]==-1 || (v[q[y]]<lv && f(q[y],lv)))
		{
			p[x] = y;
			q[y] = x;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[i].push_back(a-1);
		e[i].push_back(b-1);
	}

	memset(p, -1, sizeof(p));
	memset(q, -1, sizeof(q));
	for(int i=0; i<n; i++)
		if(!f(i, i+1))
		{
			printf("-1\n");
			return 0;
		}

	for(int i=0; i<n; i++)
		printf("%d\n", p[i]+1);
	return 0;
}
