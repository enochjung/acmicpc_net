#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
int a[110], b[110], visited[110];
vector<int> v[110];

bool f(int x, int lv)
{
	visited[x] = lv;

	int size = (int)v[x].size();
	for(int i=0; i<size; i++)
	{
		int y = v[x][i];
		if(b[y]==-1 || (visited[b[y]]<lv && f(b[y], lv)))
		{
			a[x] = y;
			b[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		v[p-1].push_back(q-1);
	}
  	
	int res = 0;

	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	for(int i=0; i<n; i++)
		if(a[i]==-1 && f(i, i+1))
			res++;

	printf("%d\n", res);
	return 0;
}
