#include <cstdio>
#include <cstring>
#define N 51

int n;
char a[N], b[N], c[N];

void r(char *t, char *s, int l)
{
	for (int i=0; i<l; ++i)
		t[i] = s[l-1-i];
}

int main()
{
    scanf("%s", a);
    n = (int)strlen(a);

	for (int i=1; i<n-1; ++i)
		for (int j=i+1; j<n; ++j)
		{
			r(b, a, i);
			r(b+i, a+i, j-i);
			r(b+j, a+j, n-j);

			if (c[0]==0 || strcmp(c,b)>0)
				strcpy(c, b);
		}

	printf("%s\n", c);
	return 0;
}
