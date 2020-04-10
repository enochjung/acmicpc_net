#include <stdio.h>

int n, d[2][3], f[2][3];

int max(int x, int y)
{
	return x>y? x : y;
}

int min(int x, int y)
{
	return x<y? x : y;
}

int main()
{
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		d[i&1][0] = a + max(d[1-i&1][0], d[1-i&1][1]);
		d[i&1][1] = b + max(d[1-i&1][0], max(d[1-i&1][1], d[1-i&1][2]));
		d[i&1][2] = c + max(d[1-i&1][1], d[1-i&1][2]);

		f[i&1][0] = a + min(f[1-i&1][0], f[1-i&1][1]);
		f[i&1][1] = b + min(f[1-i&1][0], min(f[1-i&1][1], f[1-i&1][2]));
		f[i&1][2] = c + min(f[1-i&1][1], f[1-i&1][2]);
	}

	printf("%d %d", max(d[n&1][0], max(d[n&1][1], d[n&1][2])), min(f[n&1][0], min(f[n&1][1], f[n&1][2])));

	return 0;
}
