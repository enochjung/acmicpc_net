#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int t, n, a[100010];
int l[100010], r[100010];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		stack<pair<int,int>> s;

		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i);

		memset(l, -1, sizeof(l));
		memset(r, -1, sizeof(r));

		for(int i=0; i<n; i++)
		{
			while(!s.empty() && s.top().second<=a[i])
			{
				r[s.top().first] = i;
				s.pop();
			}
			s.push({i, a[i]});
		}
		while(!s.empty()) s.pop();

		for(int i=n-1; i>=0; i--)
		{
			while(!s.empty() && s.top().second<=a[i])
			{
				l[s.top().first] = i;
				s.pop();
			}
			s.push({i, a[i]});
		}

		int res = 0;
		for(int i=0; i<n-1; i++)
		{
			int w = 0;
			int p=i, q=i+1;
			int bh = 0;
			
			while(!((a[p]>a[q] && r[q]==-1) || (a[p]<=a[q] && l[p]==-1)))
			{
				if(a[p] > a[q])
				{
					w += (a[q]-bh)*(q-p);
					bh = a[q];
					q = r[q];
				}
				else if(a[p] < a[q])
				{
					w += (a[p]-bh)*(q-p);
					bh = a[p];
					p = l[p];
				}
				else
				{
					w += (a[p]-bh)*(q-p);
					bh = a[p];
					p = l[p];
					q = r[q];
				}
			}

			if(res < w) res = w;
		}

		printf("%d\n", res);
	}
	return 0;
}
