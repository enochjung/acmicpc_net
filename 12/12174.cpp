#include <cstdio>

int t, b;
char s[8010];

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d %s", &b, s);
		printf("Case #%d: ", tc);
		for(int i=0; i<b; ++i)
		{
			char c = 0;
			for(int j=0; j<8; ++j)
			{
				c <<= 1;
				if(s[i*8+j] == 'I')
					c |= 1;
			}
			printf("%c", c);
		}
		printf("\n");
	}

	return 0;
}
