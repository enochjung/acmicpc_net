#include <cstdio>
#include <vector>
#define N 100010

using namespace std;

int m, k, cnt[N], req[N];
vector<int> v[N];

int main()
{
	scanf("%*d %d %d", &m, &k);
	while(m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		++req[y];
	}

	bool liar = false;
	while(k--)
	{
		int n, a;
		scanf("%d %d", &n, &a);
		
		if(n == 1)
		{
			if(req[a] > 0)
			{
				liar = true;
				break;
			}
			if(cnt[a] == 0)
				for(int y : v[a])
					--req[y];
			++cnt[a];
		}
		else
		{
			if(cnt[a] == 0)
			{
				liar = true;
				break;
			}
			if(cnt[a] == 1)
				for(int y : v[a])
					++req[y];
			--cnt[a];
		}
	}
	printf("%s", liar? "Lier!" : "King-God-Emperor");
	return 0;
}
