#include <stdio.h>
#define R 9901

int n;
int d[100010][3];

int main()
{
	scanf("%d", &n);
	
	d[0][0] = 1;
	for(int i=1; i<=n; i++)
	{
		d[i][0] = (d[i-1][0]+d[i-1][1]+d[i-1][2]) % R;
		d[i][1] = (d[i-1][0]+d[i-1][2]) % R;
		d[i][2] = (d[i-1][0]+d[i-1][1]) % R;
	}

	printf("%d", (d[n][0]+d[n][1]+d[n][2]) % R);

	return 0;
}
