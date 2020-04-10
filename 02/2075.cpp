#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		q.push(v);
	}
	for(int i=1; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			int v;
			scanf("%d", &v);
			q.push(v);
			q.pop();
		}
	printf("%d", q.top());
	return 0;
}
