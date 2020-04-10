#include <cstdio>
#include <stack>

using namespace std;

int n, a[100010];
stack<int> s;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	for(int v=1,i=0; v<=n; v++)
	{
		s.push(v);
		while(!s.empty() && s.top()==a[i])
		{
			s.pop();
			i++;
		}
	}

	if(!s.empty())
	{
		printf("NO\n");
		return 0;
	}
	for(int v=1,i=0; v<=n; v++)
	{
		s.push(v);
		printf("+\n");
		while(!s.empty() && s.top()==a[i])
		{
			s.pop();
			printf("-\n");
			i++;
		}
	}
}
