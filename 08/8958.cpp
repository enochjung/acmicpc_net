#include <cstdio>

int t;
char s[90];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%s", s);
		
		int sum=0, cnt=0;
		for(int i=0; s[i]; i++)
		{
			if(s[i] == 'O')
				cnt++;
			else
				cnt = 0;
			sum += cnt;
		}

		printf("%d\n", sum);
	}
	return 0;
}
