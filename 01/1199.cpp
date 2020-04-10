#include <cstdio>
#include <stack>

using namespace std;

int n, e;
int a[1010][1010];
stack<int> p, q;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", a[i]+j);
			e += a[i][j];
		}
		if(e&1)
		{
			printf("-1\n");
			return 0;
		}
	}

	e /= 2;
	p.push(0);

	while(e)
	{
		bool finish = false;
		int i = p.top();

		for(int j=0; j<n; j++)
			if(a[i][j])
			{
				a[i][j]--;
				a[j][i]--;
				e--;
				finish = true;
				p.push(j);
				break;
			}

		if(!finish)
		{
			q.push(p.top());
			p.pop();
		}
	}

	while(!p.empty())
	{
		q.push(p.top());
		p.pop();
	}

	while(!q.empty())
	{
		printf("%d ", q.top()+1);
		q.pop();
	}
	return 0;
}
