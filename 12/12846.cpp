#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

struct st
{
	int v, i;
};

int n;
long long res;
stack<st> s;

long long pop(int idx)
{
	st ss = s.top();
	s.pop();
	return 1LL*ss.v*(idx-ss.i);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);

		int idx = i;
		while(!s.empty() && s.top().v>=v)
		{
			idx = s.top().i;
			res = max(res, pop(i));
		}
		s.push({v, idx});
	}
	while(!s.empty())
		res = max(res, pop(n));

	printf("%lld", res);
	return 0;
}
