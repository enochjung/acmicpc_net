#include <cstdio>
#define MID 1000010
#define R 1000000000

int n, d[2000020];

int main()
{
	scanf("%d", &n);

	d[MID] = 0;
	d[MID+1] = 1;
	for(int i=2; i<=n; i++)
		d[MID+i] = (d[MID+i-1]+d[MID+i-2]) % R;
	for(int i=-1; i>=n; i--)
		d[MID+i] = (d[MID+i+2]-d[MID+i+1]) % R;
	
	printf("%d\n%d\n", d[MID+n]>0?1:(d[MID+n]<0?-1:0), d[MID+n]<0?-d[MID+n]:d[MID+n]);
	return 0;
}
