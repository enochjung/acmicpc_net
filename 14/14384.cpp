#include <cstdio>
#define N 110

int t;
char s[N];

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%s", s);

		int i, res=0;
		for(i=0; s[i+1]; ++i)
			if(s[i] != s[i+1])
				++res;
		if(s[i] == '-')
			++res;
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}
