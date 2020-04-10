#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int n, m;
map<string,int> si;
map<int,string> is;

int main()
{
	scanf("%d %d", &n, &m);

	char s[30];
	string str;
	for(int i=1; i<=n; i++)
	{
		scanf("%s", s);
		str.assign(s);

		si[str] = i;
		is[i] = str;
	}
	for(int i=0; i<m; i++)
	{
		scanf("%s", s);
		str.assign(s);

		if(s[0] >= 'A')
			printf("%d\n", si[str]);
		else
			printf("%s\n", is[atoi(s)].c_str());
	}

	return 0;
}
