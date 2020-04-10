#include <cstdio>
#include <cstring>
#include <algorithm>
#define FAIL -999999

using namespace std;

int t, n, m, a[10];
int d[5010][110];

int f(int x, int lv)
{
	if(lv==0 && x==0)
		return 0;
	if(lv==0)
		return FAIL;
	if(d[x][lv] == -1)
	{
		d[x][lv] = FAIL;
		for(int i=0; i<m; ++i)
			if(x >= a[0]*(lv-1)*lv/2+a[i]*lv)
				d[x][lv] = max(d[x][lv], f(x-a[i]*lv,lv-1)+a[i]);
	}
	return d[x][lv];
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		memset(d, -1, sizeof(d));

		scanf("%d %d", &n, &m);
		for(int i=0; i<m; ++i)
			scanf("%d", a+i);

		sort(a, a+m);

		int res = -1;
		for(int i=1; i<100; ++i)
			res = max(res, f(n,i));
		printf("%d\n", res);
	}

	return 0;
}
