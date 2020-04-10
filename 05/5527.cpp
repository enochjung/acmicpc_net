#include <cstdio>
#include <algorithm>

using std::max;

int n;
int d[2][3] = {{1, 1, 1}};

int main()
{
	int p, q, res=0;

	scanf("%d %d", &n, &p);
	for(int i=1; i<n; ++i)
	{
		scanf("%d", &q);

		if(p != q)
		{
			d[i&1][0] = d[(i-1)&1][0]+1;
			d[i&1][1] = d[(i-1)&1][1]+1;
			d[i&1][2] = d[(i-1)&1][2]+1;
		}
		else
		{
			d[i&1][0] = 1;
			d[i&1][1] = d[(i-1)&1][0]+1;
			d[i&1][2] = d[(i-1)&1][1]+1;
		}

		res = max({res, d[i&1][0], d[i&1][1], d[i&1][2]});
		p = q;
	}

	printf("%d", res);
	return 0;
}
