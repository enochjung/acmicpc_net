#include <cstdio>
#include <algorithm>

using namespace std;

int m, n;
char a[60][60];

int main()
{
	scanf("%d %d", &m, &n);
	for(int i=0; i<m; ++i)
		scanf("%s", a[i]);

	int res = 99;
	for(int p=0; p<m-7; ++p)
		for(int q=0; q<n-7; ++q)
		{
			int cnt = 0;
			for(int i=p; i<p+8; ++i)
				for(int j=q; j<q+8; ++j)
					if(a[i][j] == ((i+j)&1? 'B' : 'W'))
						++cnt;
			res = min(res, min(cnt, 64-cnt));
		}

	printf("%d", res);
	return 0;
}
