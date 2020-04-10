#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> q;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int v;
		scanf("%d", &v);
		
		if(v)
			q.push(v);
		else
		{
			if(q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
	}

	return 0;
}
