#include <cstdio>

int n;
bool a[110][110];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			int v;
			scanf("%d", &v);
			a[i][j] = v;
		}

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(a[i][k] && a[k][j])
					a[i][j] = true;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
