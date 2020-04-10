#include <cstdio>
#include <stack>

using namespace std;

int t, n, d[50]={0,1};

int main()
{
	for(int i=2; i<45; i++)
		d[i] = d[i-1]+d[i-2];

	for(scanf("%d",&t); t--;)
	{
		stack<int> res;

		scanf("%d", &n);
		for(int i=44; i>=1; i--)
			if(n >= d[i])
			{
				res.push(d[i]);
				n -= d[i];
			}

		while(!res.empty())
		{
			printf("%d ", res.top());
			res.pop();
		}
		printf("\n");
	}

	return 0;
}
