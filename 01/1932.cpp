#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int n, a[510][510];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++)
			scanf("%d", &a[i][j]);

	for(int i=n-2; i>=0; i--)
		for(int j=0; j<=i; j++)
			a[i][j] += MAX(a[i+1][j], a[i+1][j+1]);

	printf("%d", a[0][0]);

	return 0;
}
