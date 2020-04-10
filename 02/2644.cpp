#include <cstdio>
#include <cstring>
#include <vector>
#define N 110

using namespace std;

int n, a, b, m;
int d[N];
vector<int> e[N];

void f(int x, int t)
{
	d[x] = t;
	for(int to : e[x])
		if(d[to] == -1)
			f(to, t+1);
}

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %d %d %d", &n, &a, &b, &m);
	while(m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	f(a, 0);
	printf("%d", d[b]);
	return 0;
}
