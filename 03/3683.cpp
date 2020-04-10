#include <cstdio>
#include <cstring>
#include <vector>
#define C 110
#define V 510

using namespace std;

int t, v;
int n, q[V], level[V];
vector<int> e[V];

void input()
{
	struct cat_lover { int i, a, b; };
	vector<cat_lover> cat;
	vector<int> dog_a[C], dog_b[C];
	int dog_num = 0;

	scanf("%*d %*d %d", &v);
	for(int i=0; i<v; ++i)
	{
		int a, b;
		char ch;
		scanf(" %c%d %*c%d", &ch, &a, &b);
		--a, --b;
		if(ch == 'C')
			cat.push_back({i, a, b});
		else
		{
			dog_a[b].push_back(dog_num);
			dog_b[a].push_back(dog_num++);
		}
	}

	n = (int)cat.size();
	for(int i=0; i<n; ++i)
	{
		for(int to : dog_a[cat[i].a])
			e[i].push_back(to);
		for(int to : dog_b[cat[i].b])
			e[i].push_back(to);
	}
}

bool f(int x, int lv)
{
	level[x] = lv;
	
	for(int y : e[x])
		if(q[y]==-1 || (level[q[y]]<lv && f(q[y],lv)))
		{
			q[y] = x;
			return true;
		}
	return false;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		input();

		int res = 0;
		memset(q, -1, sizeof(q));
		memset(level, -1, sizeof(level));
		for(int i=0; i<n; i++)
			if(f(i, i))
				++res;
		printf("%d\n", v-res);

		for(int i=0; i<n; ++i)
			e[i].resize(0);
	}
	return 0;
}
