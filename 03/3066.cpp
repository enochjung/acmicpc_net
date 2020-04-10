#include <cstdio>
#include <algorithm>
#define N 40010

using namespace std;

int t, n;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int cnt=0, d[N]={};

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			int v;
			scanf("%d", &v);
			
			int idx = (int)(lower_bound(d, d+cnt, v) - d);
			d[idx] = v;
			if(idx == cnt)
				++cnt;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
