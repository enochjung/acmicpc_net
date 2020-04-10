#include <cstdio>
#include <stack>

using namespace std;

int n, t;
stack<int> s;

int main()
{
	scanf("%d", &n);
	t = 1;
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);

		while(!s.empty() && s.top()==t)
		{
			++t;
			s.pop();
		}
		if(v == t)
			++t;
		else if(s.empty() || v<s.top())
			s.push(v);
		else
		{
			printf("Sad");
			return 0;
		}
	}

	printf("Nice");
	return 0;
}
