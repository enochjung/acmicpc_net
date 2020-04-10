#include <cstdio>
#define N 110

int n;
char s[N][N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%s", s[i]);

	int r=0, c=0;
	for(int i=0; i<n; ++i)
	{
		bool seat=false, empty=false;
		for(int j=0; j<n; ++j)
		{
			if(s[i][j] == '.')
			{
				if(empty && !seat)
				{
					seat = true;
					++r;
				}
				empty = true;
			}
			else
				seat = empty = false;
		}
	}
	for(int j=0; j<n; ++j)
	{
		bool seat=false, empty=false;
		for(int i=0; i<n; ++i)
		{
			if(s[i][j] == '.')
			{
				if(empty && !seat)
				{
					seat = true;
					++c;
				}
				empty = true;
			}
			else
				seat = empty = false;
		}
	}

	printf("%d %d", r, c);
	return 0;
}
