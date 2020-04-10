#include <cstdio>
#include <stack>

using namespace std;

int n, a[500010];
int r[500010];
stack<int> s;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	for(int i=n-1; i>=0; i--)
	{
		while(!s.empty() && a[s.top()]<=a[i])
		{
			r[s.top()] = i+1;
			s.pop();
		}
		s.push(i);
	}

	for(int i=0; i<n; i++)
		printf("%d ", r[i]);

	return 0;
}
