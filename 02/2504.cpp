#include <cstdio>
#include <stack>

using namespace std;

char a[40];
stack<int> s;

int f()
{
	int sum = 0;
	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
			s.push(-1);
		else if(a[i] == '[')
			s.push(-2);
		else if(a[i] == ')')
		{
			int v = 0;
			while(!s.empty() && s.top()>0)
			{
				v += s.top();
				s.pop();
			}
			if(s.empty() || s.top()!=-1)
				return 0;
			s.pop();
			s.push(v==0? 2 : v*2);
		}
		else
		{
			int v = 0;
			while(!s.empty() && s.top()>0)
			{
				v += s.top();
				s.pop();
			}
			if(s.empty() || s.top()!=-2)
				return 0;
			s.pop();
			s.push(v==0? 3 : v*3);
		}
	}
	while(!s.empty() && s.top()>0)
	{
		sum += s.top();
		s.pop();
	}
	return s.empty()? sum : 0;
}

int main()
{
	scanf("%s", a);
	printf("%d\n", f());
	return 0;
}
