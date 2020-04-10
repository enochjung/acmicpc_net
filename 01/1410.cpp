#include <cstdio>
#include <cstring>
#define MOD 1000003

int n, k, l;
char p[20][60];
int d[60][1<<15];

int count(int x)
{
	int cnt = 0;
	for(; x; ++cnt)
		x -= x&-x;
	return cnt;
}

int index(int lv, int v, int a)
{
	for(int i=0,j=1; i<n; ++i,j<<=1)
		if(p[i][lv]!='?' && p[i][lv]!='a'+a)
			v &= v^j;
	return v;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%s", p[i]);

	l = (int)strlen(p[0]);
	d[0][(1<<n)-1] = 1;
	for(int i=0; i<l; ++i)
		for(int j=1; j<(1<<n); ++j)
			if(d[i][j] && count(j)>=k)
				for(int a=0; a<26; ++a)
				{
					int idx = index(i, j, a);
					d[i+1][idx] = (d[i+1][idx]+d[i][j])%MOD;
				}

	int res = 0;
	for(int j=1; j<(1<<n); ++j)
		if(count(j) == k)
			res = (res+d[l][j])%MOD;
	printf("%d", res);
	return 0;
}
