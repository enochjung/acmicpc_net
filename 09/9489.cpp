#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1010

using namespace std;

int n, k;

int main()
{
	while(1)
	{
		int t;
		vector<int> p, c[N];

		scanf("%d %d", &n, &k);
		if(n == 0)
			break;

		p.resize(n+2);
		p[1] = 0;
		c[0].push_back(1);

		int b = -1;
		int pi = 0;
		for(int i=2; i<n+2; ++i)
		{
			int v;
			scanf("%d", &v);
			if(v > b+1)
				++pi;
			p[i] = pi;
			c[pi].push_back(i);

			b = v;
			if(v == k)
				t = i;
		}

		int sum = 0;
		for(int i : c[p[p[t]]])
			sum += (int)c[i].size();
		printf("%d\n", sum-(int)c[p[t]].size());
	}

	return 0;
}
