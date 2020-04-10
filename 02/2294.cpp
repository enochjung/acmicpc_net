#include <stdio.h>

int n, k, a[110], d[10010];

inline int min(int x, int y)
{
	return x<y? x : y;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	for(int i=1; i<=k; i++)
		d[i] = 99999;

	d[0] = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j+a[i]<=k; j++)
			d[j+a[i]] = min(d[j+a[i]], d[j]+1);

	printf("%d\n", d[k]==99999? -1 : d[k]);
	return 0;
}
