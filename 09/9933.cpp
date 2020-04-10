#include <cstdio>
#include <cstring>

int n, d[110];
char a[110][20];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%s", a[i]);
		d[i] = (int)strlen(a[i]);
	}

	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(d[i] == d[j])
			{
				bool flag = true;
				for(int k=0; k<d[i]/2; k++)
					if(a[i][k] != a[j][d[i]-1-k])
					{
						flag = false;
						break;
                    }

				if(flag)
				{
					printf("%d\n%c", d[i], a[i][d[i]/2]);
					return 0;
				}
			}
	return 0;
}
