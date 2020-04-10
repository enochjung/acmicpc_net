#include <cstdio>
#define L 8010
#define G 810
#define INF (1LL<<62)

int l, g;
long long d[L][G], a[L];

void update(int i, int s, int e, int p, int q)
{
	if(s >= e)
		return;

	int mid=(s+e)/2, t=0;
	d[mid][i] = mid? INF : 0;
	for(int j=p; j<=q && j<mid; ++j)
	{
		long long val = d[j][i-1]+(a[mid]-a[j])*(mid-j);
		if(d[mid][i] > val)
		{
			d[mid][i] = val;
			t = j;
		}
	}

	update(i, s, mid, p, t);
	update(i, mid+1, e, t, q);
}

int main()
{
	scanf("%d %d", &l, &g);
	for(int i=0; i<l; ++i)
	{
		int v;
		scanf("%d", &v);
		a[i+1] = a[i]+v;
	}
	for(int i=1; i<=l; ++i)
		d[i][0] = INF;
	for(int i=1; i<=g; ++i)
		update(i, 0, l+1, 0, l);
	printf("%lld", d[l][g]);
	return 0;
}
