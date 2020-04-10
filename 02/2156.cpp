#include <stdio.h>

int n, a[10010], d[10010][2];

int max(int x, int y)
{
	return x>y?x:y;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", a+i);

	d[1][0] = a[1];
	d[1][1] = a[1];
	d[2][0] = a[2];
	d[2][1] = a[1]+a[2];

	for(int i=3; i<=n; i++)
	{
		d[i][0] = a[i] + max(max(d[i-2][0], d[i-2][1]), max(d[i-3][0], d[i-3][1]));
		d[i][1] = a[i] + d[i-1][0];
	}

	printf("%d", max(max(d[n][0], d[n][1]), max(d[n-1][0], d[n-1][1])));

	return 0;
}
