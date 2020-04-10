#include <cstdio>
#define N 1010

int n, a, b;
int x[N][N];

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &x[i][j]);
	--a, --b;

	bool happy = true;
	for(int i=0; i<n; ++i)
		happy &= x[a][b]>=x[i][b] && x[a][b]>=x[a][i];

	printf("%s", happy? "HAPPY" : "ANGRY");
	return 0;
}
