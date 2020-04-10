#include <cstdio>

int t, r;
char s[30];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %s", &r, s);
		
		for(int i=0; s[i]; i++)
			for(int k=0; k<r; k++)
				printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}
