#include <cstdio>
#include <map>

using namespace std;

char s[90];
map<char,const char*> m;

int main()
{
	m[' '] = "%20";
	m['!'] = "%21";
	m['$'] = "%24";
	m['%'] = "%25";
	m['('] = "%28";
	m[')'] = "%29";
	m['*'] = "%2a";

	while(true)
	{
		scanf(" %[^\n]", s);
		if(s[0] == '#')
			break;

		for(int i=0; s[i]; ++i)
		{
			if(m.find(s[i]) == m.end())
				printf("%c", s[i]);
			else
				printf("%s", m[s[i]]);
		}
		printf("\n");
	}

	return 0;
}
