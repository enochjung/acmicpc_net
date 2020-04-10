#include <cstdio>
#include <algorithm>
#include <set>
#define N 300010

using namespace std;

int n;
long long c;
int d[N];
set<int> s;

int left(set<int>::iterator it)
{
	if(it == s.begin())
		return -1;
	return d[*(--it)];
}

int right(set<int>::iterator it)
{
	if(++it == s.end())
		return -1;
	return d[*it];
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int v;
		scanf("%d", &v);

		auto it = s.insert(v);
		d[v] = max(left(it.first), right(it.first))+1;
		c += d[v];

		printf("%lld\n", c);
	}

	return 0;
}
