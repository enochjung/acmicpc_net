#include <cstdio>
#include <algorithm>

using namespace std;

int p, w;
char s[1010];
int d[8] = {3, 3, 3, 3, 3, 4, 3, 4};
pair<int,int> b[26];

int main()
{
	scanf("%d %d %[^\n]", &p, &w, s);
	
	int g=0, c=1;
	for(int i=0; i<26; ++i)
	{
		b[i] = {g, c};
		if(c++ == d[g])
			++g, c=1;
	}

	int res = 0;
	for(int i=0; s[i]; ++i)
	{
		if(s[i] == ' ')
			res += p;
		else
		{
			if(i>0 && s[i-1]!=' ' && b[s[i]-'A'].first==b[s[i-1]-'A'].first)
				res += w;
			res += p*b[s[i]-'A'].second;
		}
	}
	printf("%d", res);
	return 0;
}
