#include <cstdio>
#include <stack>
#define N 101

using namespace std;

char a[N];
stack<char> s;

int main()
{
	scanf("%s", a);

	for (int i=0; a[i]; ++i)
	{
		char c = a[i];
		if ('A'<=c && c<='Z')
			putchar(c);
		else if (c=='+' || c=='-')
		{
			while (!s.empty() && s.top()!='(')
			{
				putchar(s.top());
				s.pop();
			}
			s.push(c);
		}
		else if (c=='*' || c=='/')
		{
			while (!s.empty() && (s.top()=='*' || s.top()=='/'))
			{
				putchar(s.top());
				s.pop();
			}
			s.push(c);
		}
		else if (c == '(')
			s.push(c);
		else
		{
			while (s.top() != '(')
			{
				putchar(s.top());
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty())
	{
		putchar(s.top());
		s.pop();
	}

	return 0;
}