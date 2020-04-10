#include <cstdio>

int n, m, t[110];
int s[110];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
		scanf("%d", t+i);

	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
		{
			int v;
			scanf("%d", &v);
			if(v == t[i])
				++s[j];
			else
				++s[t[i]-1];
		}

	for(int i=0; i<n; ++i)
		printf("%d\n", s[i]);
	return 0;
}
