#include <cstdio>
#include <cstring>

int n, m, p[26];
char a[40], b[40];
char c[40][40];

int main()
{
	scanf("%s %s", a, b);

	n = (int)strlen(a);
	m = (int)strlen(b);
	memset(p, -1, sizeof(p));
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			c[i][j] = '.';
	
	for(int i=0; i<m; ++i)
		if(p[b[i]-'A'] == -1)
			p[b[i]-'A'] = i;
	for(int j=0; j<n; ++j)
		if(p[a[j]-'A'] != -1)
		{
			int i = p[a[j]-'A'];

			for(int w=0; w<n; ++w)
				c[i][w] = a[w];
			for(int k=0; k<m; ++k)
				c[k][j] = b[k];
			break;
		}

	for(int i=0; i<m; ++i)
		printf("%s\n", c[i]);
	return 0;
}
