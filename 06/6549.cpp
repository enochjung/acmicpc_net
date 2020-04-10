#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int n;

int main()
{
	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
			break;

		long long res = 0;
		stack<pair<int,int>> s;
		for(int i=0; i<=n; i++)
		{
			int h = -1;
			if(i < n)
				scanf("%d", &h);

			int idx = i;
			while(!s.empty() && h<=s.top().first)
			{
				idx = s.top().second;
				res = max(res, 1LL*s.top().first*(i-idx));
				s.pop();
			}
			s.push({h, idx});
		}

		printf("%lld\n", res);
	}
	return 0;
}
