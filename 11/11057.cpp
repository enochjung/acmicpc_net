#include <cstdio>
#define R 10007

int n;
int d[1010][10];

int main()
{
	scanf("%d", &n);

	for(int i=0; i<10; i++)
		d[1][i] = 1;
	for(int i=1; i<n; i++)
		for(int j=0; j<10; j++)
			for(int k=j; k<10; k++)
				d[i+1][k] = (d[i+1][k]+d[i][j]) % R;

	int sum = 0;
	for(int i=0; i<10; i++)
		sum = (sum+d[n][i]) % R;
	printf("%d\n", sum);
	return 0;
}
