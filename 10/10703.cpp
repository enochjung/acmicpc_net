#include <cstdio>
#include <algorithm>
#define N 3010

using namespace std;

int r, s;
char a[N][N], b[N][N];

int main()
{
	scanf("%d %d", &r, &s);
	for(int i=0; i<r; ++i)
		scanf("%s", a[i]);

	int d=9999;
	for(int j=0; j<s; ++j)
	{
		int p = -9999;
		for(int i=0; i<r; ++i)
		{
			if(a[i][j] == 'X')
				p = i;
			else if(a[i][j] == '#')
				d = min(d, i-p-1);
		}
	}

	for(int i=0; i<r; ++i)
		for(int j=0; j<s; ++j)
			b[i][j] = '.';
	for(int i=0; i<r; ++i)
		for(int j=0; j<s; ++j)
		{
			if(a[i][j] == 'X')
				b[i+d][j] = 'X';
			else if(a[i][j] == '#')
				b[i][j] = '#';
		}

	for(int i=0; i<r; ++i)
		printf("%s\n", b[i]);
	return 0;
}
