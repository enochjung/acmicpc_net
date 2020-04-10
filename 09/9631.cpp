#include <cstdio>
#define N 10010
#define R 1000000007

int t;
char s[N];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%s", s);

		long long res = 1;

		for(int i=0; s[i]; ++i)
			if(s[i] == '?')
			{
				int j = i+1;
				while(s[j] == '?')
					++j;
				if(i>0 && s[j]!=0 && s[i-1]!=s[j])
					res = (res*(j-i+1))%R;
				i = j-1;
			}

		printf("%lld\n", res);
	}

	return 0;
}
