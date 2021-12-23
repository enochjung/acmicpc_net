#include <cstdio>
#include <cstring>
#include <vector>
#define N 10
#define M (N*2)

using namespace std;
 
int n, q[M], v[M];
vector<int> e[M];

bool f(int x, int lv)
{
	v[x] = lv;

	for (int to : e[x])
		if (!q[to] || (v[q[to]]<lv && f(q[to],lv)))
		{
			q[to] = x;
			return true;
		}

	return false;
}
 
int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			int val;
			scanf("%d", &val);
			if (val == 1)
				e[i+j+1].push_back(i-j+n);
		}

	int res = 0;
	for(int i=1; i<n*2; ++i)
		if(f(i, i))
			++res;

	printf("%d", res);
	return 0;
}