#include <cstdio>
#include <stack>

using namespace std;

int n;
stack<int> s;

int main()
{
	scanf("%d", &n);
	++n;
	while(n)
	{
		s.push(n%10);
		n /= 10;
	}
	while(!s.empty())
	{
		printf("%d", s.top()? s.top() : 1);
		s.pop();
	}

	return 0;
}
