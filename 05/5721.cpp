#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;

int main()
{
	while(1)
	{
		scanf("%d %d", &m, &n);
		if(!m)
			break;

		vector<int> c(m);

		for(int i=0; i<m; ++i)
		{
			vector<int> d(n);
			for(int j=0; j<n; ++j)
			{
				int v;
				scanf("%d", &v);
				d[j] = max(j>1?d[j-2]:0, j>2?d[j-3]:0) + v;
			}
			c[i] = max(i>1?c[i-2]:0, i>2?c[i-3]:0) + max(d[n-1], n>1?d[n-2]:0);
		}

		printf("%d\n", max(c[m-1], m>1?c[m-2]:0));
	}

	return 0;
}
