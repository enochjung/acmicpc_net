#include <cstdio>
#include <stack>

using namespace std;

int t;
char a[60];

bool f()
{
	stack<bool> s;
	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
			s.push(true);
		else
		{
			if(!s.empty())
				s.pop();
			else
				return false;
		}
	}
	return s.empty();
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%s", a);
		printf("%s\n", f()? "YES" : "NO");
	}
	return 0;
}
