#include <cstdio>
#include <algorithm>
#define R 2010

using namespace std;

int r, c, m;
int d[R][R], t[R];
pair<int,int> p;

int maxp(int i, int j)
{
	int q = d[(i+r-1)%r][(j+1)%c];
	int w = d[i][(j+1)%c];
	int e = d[(i+1)%r][(j+1)%c];
	return q>w && q>e? -1 : (w>e? 0 : 1);
}

void move(int k)
{
	int &x = p.first;
	int &y = p.second;

	while(y && k)
	{
		x = (x+r+maxp(x, y))%r;
		y = (y+1)%c;
		--k;
	}

	int v[R] = {};
	int g, s;
	for(int i=1,j=x; ; ++i,j=t[j])
	{
		if(v[j])
		{
			g = v[j]-1;
			s = i-v[j];
			break;
		}
		else
			v[j] = i;
	}

	while(g && k>=c)
	{
		x = t[x];
		--g;
		k -= c;
	}
	k %= c*s;
	while(k >= c)
	{
		x = t[x];
		k -= c;
	}

	while(k)
	{
		x = (x+r+maxp(x, y))%r;
		y = (y+1)%c;
		--k;
	}
}

void change(int a, int b, int e)
{
	d[a][b] = e;

	for(int w=-1; w<=1; ++w)
	{
		int i = (a+w+r)%r;
		int j = (b+c-1)%c;

		int m=i, n=j;
		do
		{
			m = (m+maxp(m,n)+r)%r;
			n = (n+1)%c;
		} while(n);

	}
}

int main()
{
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j)
			scanf("%d", &d[i][j]);

	for(int i=0; i<r; ++i)
	{
		int x = i;
		for(int j=0; j<c; ++j)
			x = (x+maxp(x, j)+r)%r;
		t[i] = x;
	}

	for(scanf("%d",&m); m--;)
	{
		char s[7];

		scanf(" %s", s);
		if(s[0] == 'm')
		{
			int k;
			scanf("%d", &k);
			move(k);
			printf("%d %d\n", p.first, p.second);
		}
		else
		{
			int a, b, e;
			scanf("%d %d %d", &a, &b, &e);
			change(a, b, e);
		}
	}

	return 0;
}
