#include <cstdio>
#include <algorithm>
#define INF 9999999

using namespace std;

int n, k, a[1000010];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int i=0, cnt=0, res=INF;
	while(a[++i] != 1);
	for(int j=i; j<=n; ++j)
		if(a[j-1] == 1)
		{
			++cnt;
			if(cnt > k)
			{
				while(a[++i] != 1);
				--cnt;
			}
			if(cnt == k)
				res = min(res, j-i);
		}

	printf("%d", res<INF? res : -1);
	return 0;
}
