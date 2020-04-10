#include <cstdio>
#include <cstring>
#define N 210
#define R 100000

int n;
long long d[N][N];
bool o[N][N], z[N][N];
char s[N];
char open[]="({[", close[]=")}]";

int f(int a, int b)
{
	if(a == b)
		return 1;
	if(a > b)
	{
		z[a][b] = true;
		return 0;
	}

	if(d[a][b] == -1)
	{
		d[a][b] = 0;
		z[a][b] = true;

		for(int i=a+2; i<=b; i+=2)
			for(int w=0; w<3; ++w)
				if((s[a]==open[w] || s[a]=='?') && (s[i-1]==close[w] || s[i-1]=='?'))
				{
					int ra = f(a+1, i-1);
					int rb = f(i, b);

					if(!z[a+1][i-1] && !z[i][b])
					{
						d[a][b] += 1LL*ra*rb;
						z[a][b] = false;
						o[a][b] |= o[a+1][i-1] | o[i][b];
						if(d[a][b] >= R)
						{
							o[a][b] = true;
							d[a][b] %= R;
						}
					}
				}
	}

	return d[a][b];
}

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %s", &n, s);
	int res = f(0, n);
	printf(o[0][n]? "%05d" : "%d", res);
	return 0;
}
