#include <cstdio>
#define R 1000000000

int n;
int d[110][10][4];

int main()
{
	scanf("%d", &n);
	
	for(int i=1; i<10; i++)
		d[1][i][i==9?2:0]= 1;

	for(int i=0; i<n; i++)
		for(int j=0; j<10; j++)
			for(int k=0; k<4; k++)
			{
				if(j > 0)
					d[i+1][j-1][k|(j==1?1:0)] = (d[i+1][j-1][k|(j==1?1:0)]+d[i][j][k]) % R;
				if(j < 9)
					d[i+1][j+1][k|(j==8?2:0)] = (d[i+1][j+1][k|(j==8?2:0)]+d[i][j][k]) % R;
			}

	int sum = 0;
	for(int i=0; i<10; i++)
		sum = (sum+d[n][i][3]) % R;
	printf("%d\n", sum);
	return 0;
}
