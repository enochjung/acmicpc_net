#include <cstdio>
#include <algorithm>

using namespace std;

int t;
char s[60];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%s", s);

		int res = 3;
		for(int i=0; s[i]; ++i)
		{
			if(s[i]=='l' && s[i+1]=='o' && s[i+2]=='l')
				res = min(res, 0);
			if(s[i]=='l' && s[i+1]=='o')
				res = min(res, 1);
			if(s[i]=='o' && s[i+1]=='l')
				res = min(res, 1);
			if(s[i]=='l' && s[i+1]=='l')
				res = min(res, 1);
			if(s[i]=='l' && s[i+2]=='l')
				res = min(res, 1);
			if(s[i]=='l' || s[i]=='o')
				res = min(res, 2);
		}

		printf("%d\n", res);
	}

	return 0;
}
