#include <cstdio>
#include <queue>

using namespace std;

struct st
{
	int p, t;
};

int s, g, f, u, d;
bool v[1000010];
queue<st> q;

int main()
{
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	q.push({s, 0});
	v[s] = true;

	while(!q.empty())
	{
		int p = q.front().p;
		int t = q.front().t;
		q.pop();

		if(p == g)
		{
			printf("%d\n", t);
			return 0;
		}
		if(p+u<=f && !v[p+u])
		{
			q.push({p+u, t+1});
			v[p+u] = true;
		}
		if(p-d>=1 && !v[p-d])
		{
			q.push({p-d, t+1});
			v[p-d] = true;
		}
	}

	printf("use the stairs\n");
	return 0;
}
