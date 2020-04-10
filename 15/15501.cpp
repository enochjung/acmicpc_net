#include <cstdio>
#define N 1000010

int n, a[2][N];
int idx[2], way[2];

int main()
{
	scanf("%d", &n);
	for(int k=0; k<2; ++k)
		for(int i=0; i<n; ++i)
		{
			scanf("%d", a[k]+i);
			if(a[k][i] == 1)
				idx[k] = i;
		}

	for(int k=0; k<2; ++k)
		way[k] = a[k][(idx[k]+n-1)%n]>a[k][(idx[k]+1)%n]? 1 : -1;

	bool flag = true;
	for(int i=0; i<n; ++i)
	{
		idx[0] = (idx[0]+way[0]+n)%n;
		idx[1] = (idx[1]+way[1]+n)%n;

		if(a[0][idx[0]] != a[1][idx[1]])
		{
			flag = false;
			break;
		}
	}

	printf("%s puzzle", flag? "good" : "bad");
	return 0;
}
