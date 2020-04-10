#include <cstdio>
#include <cstring>

int n;
char a[1010][110];
int res;

int main()
{
	while(1)
	{
		memset(a, 0, sizeof(a));
		res = 0;

		scanf("%d", &n);
		getchar();

		if(n == 0)
			return 0;

		for(int i=0; i<n; i++)
			fgets(a[i], sizeof(a[i]), stdin);

		for(int i=0; i<n; i++)
			while(a[i][res]!=' ' && a[i][res]!='\n' && a[i][res]!=0)
				res++;
		
		printf("%d\n", res+1);
	}
	return 0;
}
