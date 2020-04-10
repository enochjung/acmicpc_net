#include <cstdio>
#include <stack>

using namespace std;

int k;
stack<int> s;

int main()
{
	for(scanf("%d",&k); k--;)
	{
		int v;
		scanf("%d", &v);
		if(v)
			s.push(v);
		else
			s.pop();
	}

	long long res = 0;
	while(!s.empty())
	{
		res += s.top();
		s.pop();
	}

	printf("%lld", res);
	return 0;
}
