#include <cstdio>
#include <stack>

using namespace std;

int n;
stack<int> s[6];

int main()
{
	scanf("%d %*d", &n);

	int res = 0;
	for(int i=0; i<n; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		
		while(!s[a].empty() && s[a].top()>b)
		{
			++res;
			s[a].pop();
		}
		if(s[a].empty() || s[a].top()<b)
		{
			++res;
			s[a].push(b);
		}
	}
	printf("%d", res);
	return 0;
}
