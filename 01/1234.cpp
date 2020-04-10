#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, r, g, b;
long long d[20][60][60];

long long p(int r, int g, int b)
{
	static bool init = false;
	static long long f[20] = {1};
	if(!init)
	{
		init = true;
		for(int i=1; i<=10; ++i)
			f[i] = f[i-1]*i;
	}
	return f[r+g+b]/(f[r]*f[g]*f[b]);
}

long long f(int k, int r, int g, int b)
{
	if(r<0 || g<0 || b<0)
		return 0;
	if(k == 0)
		return 1;

	if(d[k][r][g] == -1)
	{
		d[k][r][g] = 0;

		if(k%3==0)
			d[k][r][g] += f(k-1, r-k/3, g-k/3, b-k/3)*p(k/3,k/3,k/3);
		if(k%2==0)
		{
			d[k][r][g] += f(k-1, r, g-k/2, b-k/2)*p(k/2,k/2,0);
			d[k][r][g] += f(k-1, r-k/2, g, b-k/2)*p(k/2,k/2,0);
			d[k][r][g] += f(k-1, r-k/2, g-k/2, b)*p(k/2,k/2,0);
		}
		d[k][r][g] += f(k-1, r-k, g, b);
		d[k][r][g] += f(k-1, r, g-k, b);
		d[k][r][g] += f(k-1, r, g, b-k);
	}
	return d[k][r][g];
}

int main()
{
	scanf("%d %d %d %d", &n, &r, &g, &b);
	memset(d, -1, sizeof(d));

	int over = r+g+b-n*(n+1)/2;
	long long res = 0;
	for(int i=max(0,over-g-b); i<=min(over,r); ++i)
		for(int j=max(0,over-i-b); j<=min(over-i,g); ++j)
		{
			int k = over-i-j;
			res += f(n, r-i, g-j, b-k);
		}
	printf("%lld", res);
	return 0;
}
