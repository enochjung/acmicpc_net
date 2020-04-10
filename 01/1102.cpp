#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 16
#define INF 0x3fffffff

using namespace std;

int n, a[N][N], p;
int d[1<<N];

int count(int x)
{
	int cnt = 0;
	for(; x; ++cnt)
		x -= x&-x;
	return cnt;
}

int f(int x)
{
	if(d[x] == -1)
	{
		if(count(x) >= p)
			d[x] = 0;
		else
		{
			d[x] = INF;
			for(int i=0; i<n; ++i)
				if((x&(1<<i)) > 0)
					for(int j=0; j<n; ++j)
						if((x&(1<<j)) == 0)
							d[x] = min(d[x], f(x|(1<<j))+a[i][j]);
		}
	}

	return d[x];
}

int main()
{
	int code = 0;
	memset(d, -1, sizeof(d));

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &a[i][j]);
	for(int i=0; i<n; ++i)
	{
		char c;
		scanf(" %c", &c);
		if(c == 'Y')
			code |= 1<<i;
	}
	scanf("%d", &p);

	int res = f(code);
	printf("%d", res<INF? res : -1);
	return 0;
}
