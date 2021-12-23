#include <cstdio>
#include <cstring>
#define R 10007

int n;
int d[53][14][14];

int f(int c, int a, int b)
{
	if (c<0 || (c>0 && b==0))
		return 0;
	if (a > b)
		return 0;
	if (c == 0)
		return a == 0;
	if (d[c][a][b] == -1)
	{
		d[c][a][b] = f(c-4, a-1, b-1);
		d[c][a][b] += f(c-3, a, b-1) * 4;
		d[c][a][b] += f(c-2, a, b-1) * 6;
		d[c][a][b] += f(c-1, a, b-1) * 4;
		d[c][a][b] += f(c, a, b-1);
		d[c][a][b] %= R;
	}

	return d[c][a][b];
}

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d", &n);

	int res = 0;
	for (int i=1; i<=13; ++i)
		res = (res + f(n, i, 13)) % R;
	printf("%d\n", res);
	return 0;
}