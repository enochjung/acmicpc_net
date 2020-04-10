#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1000010

using namespace std;

int n;
int leaf;
vector<int> e[N], visited;

int f(int x, bool l)
{
	int cnt = 0;

	visited[x] = true;
	if(e[x].size()==1 && l)
		++cnt;

	for(int to : e[x])
		if(!visited[to])
			cnt += f(to, !l);

	return cnt;
}

int main()
{
	scanf("%d", &n);
	leaf = n;
	visited.resize(n);
	for(int i=0; i<n-1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		if(e[a].size() == 1)
			--leaf;
		if(e[b].size() == 1)
			--leaf;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	if(n == 2)
		printf("0");
	else if(leaf == n-1)
		printf("%d", leaf-1);
	else
	{
		int val = f(0, true);
		printf("%d", max(val, leaf-val));
	}
	return 0;
}
