#include <cstdio>
#include <string>

using namespace std;

int m;
char s[260];
int idx;

string f()
{
	string res = "";

	char b = 0;
	for(; s[idx]!=0 && s[idx]!=')'; ++idx)
	{
		if(s[idx] == '(')
		{
			++idx;
			string ret = f();
			res += ret.size()==1 || b!='-'? ret : "("+ret+")";
		}
		else if(s[idx] != ' ')
		{
			res += s[idx];
			b = s[idx];
		}
	}

	return res;
}

int main()
{
	for(scanf("%d",&m); m--;)
	{
		idx = 0;
		scanf(" %[^\n]", s);
		printf("%s\n", f().c_str());
	}
	return 0;
}
