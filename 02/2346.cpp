#include <cstdio>
#include <list>

using namespace std;

struct st
{
	int x, v;
};

int n;
list<st> l;

void move(list<st>::iterator &it, int w)
{
	if(w > 0)
	{
		++it;
		if(it == l.end())
			it = l.begin();
	}
	else
	{
		if(it == l.begin())
			it = l.end();
		--it;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		int v;
		scanf("%d", &v);
		l.push_back({i, v});
	}

	printf("1 ");
	auto it = l.begin();
	for(int i=0; i<n-1; ++i)
	{
		int c = it->v>0? it->v : -it->v;
		int w = it->v>0? 1 : -1;
		auto tmp = it;
		move(it, w);
		l.erase(tmp);
		while(--c)
			move(it, w);
		printf("%d ", it->x);
	}

	return 0;
}
