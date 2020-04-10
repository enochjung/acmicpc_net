#include <cstdio>
#include <stack>

using namespace std;

int n;
char s[100010];

bool good()
{
	stack<bool> t;

	for(int i=0; s[i]; ++i)
	{
		if(s[i] == 'A')
		{
			if(t.empty() || t.top())
				t.push(false);
			else
				t.pop();
		}
		else
		{
			if(t.empty() || !t.top())
				t.push(true);
			else
				t.pop();
		}
	}
	return t.empty();
}

int main()
{
	scanf("%d", &n);
	int res = 0;
	while(n--)
	{
		scanf("%s", s);
		if(good())
			++res;
	}
	printf("%d", res);
	return 0;
}
