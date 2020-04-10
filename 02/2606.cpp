#include <cstdio>
#include <vector>

using namespace std;

int m;
bool v[110];
vector<int> e[110];

int f(int x)
{
	int cnt = 1;

	v[x] = true;
	for(int to : e[x])
		if(!v[to])
			cnt += f(to);

	return cnt;
}

int main()
{
	scanf("%*d %d", &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}

	printf("%d", f(1)-1);
	return 0;
}
