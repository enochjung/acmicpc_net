#include <cstdio>
#include <algorithm>
#include <stack>
#define N 1010

using namespace std;

struct st
{
	int h, p;
};

int n, m;

int main()
{
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0)
			break;

		int res = 0;
		int h[N] = {};

		while(n--)
		{
			stack<st> s;

			for(int i=0; i<=m; ++i)
			{
				int v = 0;
				if(i < m)
					scanf("%d", &v);
				h[i] = v? h[i]+1 : 0;

				int idx = i;
				while(!s.empty() && s.top().h>=h[i])
				{
					idx = s.top().p;
					res = max(res, s.top().h*(i-idx));
					s.pop();
				}
				s.push({h[i], idx});
			}
		}
		printf("%d\n", res);
	}
	
	return 0;
}
