#include <cstdio>
#include <cstring>
#define N 20

int a, b;
double d[N][N][N];
bool p[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};

double f(int i, int j, int k)
{
	if(d[i][j][k] < -1)
	{
		if(i == 18)
			d[i][j][k] = p[j] || p[k];
		else
			d[i][j][k] = (f(i+1,j+1,k+1)*a*b + f(i+1,j,k+1)*(100-a)*b + f(i+1,j+1,k)*a*(100-b) + f(i+1,j,k)*(100-a)*(100-b))/10000;
	}

	return d[i][j][k];
}

int main()
{
	scanf("%d %d", &a, &b);
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			for(int k=0; k<N; ++k)
				d[i][j][k] = -10;
	printf("%.7lf", f(0, 0, 0));
	return 0;
}
