#include <cstdio>
#define R 1000000000

int n;
int d[110][10];

int main()
{
	scanf("%d", &n);

	for(int i=1; i<10; i++)
		d[1][i] = 1;
	for(int i=1; i<n; i++)
		for(int j=0; j<10; j++)
		{
			if(j > 0)
				d[i+1][j-1] = (d[i+1][j-1]+d[i][j]) % R;
			if(j < 9)
				d[i+1][j+1] = (d[i+1][j+1]+d[i][j]) % R;
		}

	int sum = 0;
	for(int i=0; i<10; i++)
		sum = (sum+d[n][i]) % R;
	printf("%d\n", sum);
	return 0;
}
