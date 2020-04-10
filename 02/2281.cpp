#include <cstdio>
#include <algorithm>
#define INF 2147483647

using std::min;

int n, m, a[1010];
int d[1010];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int k, blank=m+1;
	for(k=n-1; k>=0; --k)
	{
		blank -= a[k]+1;
		if(blank < 0)
			break;
	}

	for(int i=k; i>=0; --i)
	{
		blank = m+1;
		d[i] = INF;

		for(int j=i; j<n; ++j)
		{
			blank -= a[j]+1;
			if(blank < 0)
				break;
			d[i] = min(d[i], d[j+1]+blank*blank);
		}
	}

	printf("%d", d[0]);
	return 0;
}
