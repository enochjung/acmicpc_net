#include <stdio.h>
#include <string.h>

int n, m, a[110], b[110];
int d[10010];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	for(int i=0; i<n; i++)
		scanf("%d", b+i);

	memset(d, -1, sizeof(d));
	d[0] = 0;

	for(int i=0; i<n; i++)
		for(int j=10000-b[i]; j>=0; j--)
			if(d[j]!=-1 && d[j+b[i]]<d[j]+a[i])
				d[j+b[i]] = d[j]+a[i];

	for(int i=0; i<=10000; i++)
		if(d[i] >= m)
		{
			printf("%d", i);
			break;
		}

	return 0;
}
