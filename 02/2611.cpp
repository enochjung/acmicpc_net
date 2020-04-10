#include <cstdio>
#include <stack>
#include <vector>
#define N 1010

using namespace std;

int n, m;
int d[N], l[N];
vector<pair<int,int>> v[N];

int main()
{
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		v[p-1].push_back({q>1? q-1 : n, -r});
	}

	bool update = true;
	while(update)
	{
		update = false;
		for(int i=0; i<n; i++)
			for(auto t : v[i])
			{
				int j = t.first;
				int r = t.second;

				if(d[j] > d[i]+r)
				{
					d[j] = d[i]+r;
					l[j] = i;
					update = true;
				}
			}
	}
	
	stack<int> res;
	for(int i=l[n]; i!=0; i=l[i])
		res.push(i);

	printf("%d\n1 ", -d[n]);
	while(!res.empty())
	{
		printf("%d ", res.top()+1);
		res.pop();
	}
	printf("1");
	return 0;
}
