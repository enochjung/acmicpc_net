#include <cstdio>

int m, s;

int main()
{
	for(scanf("%d",&m); m--;)
	{
		char a[10];
		int v;

		scanf("%s", a);
		switch(a[1])
		{
		case 'd':
			scanf("%d", &v);
			s |= 1<<(v-1);
			break;
		
		case 'e':
			scanf("%d", &v);
			s = ~((~s)|(1<<(v-1)));
			break;

		case 'h':
			scanf("%d", &v);
			printf("%d\n", (s&(1<<(v-1)))>0);
			break;

		case 'o':
			scanf("%d", &v);
			s ^= 1<<(v-1);
			break;

		case 'l':
			s = (1<<20)-1;
			break;

		case 'm':
			s = 0;
			break;
		}
	}
	return 0;
}
