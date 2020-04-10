#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m, k1, k2, res[2];
int q[310], v[310];
vector<int> e[2][310];

bool f(int t, int x, int lv)
{
	v[x] = lv;

	for(int y : e[t][x])
		if(q[y]==-1 || (v[q[y]]<lv && f(t,q[y],lv)))
		{
			q[y] = x;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k1, &k2);
	for(int i=0; i<k1+k2; i++)	
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[i>=k1][a-1].push_back(b-1);
	}
	
	for(int t=0; t<2; t++)
	{
		memset(q, -1, sizeof(q));
		memset(v, -1, sizeof(v));
		for(int i=0; i<n; i++)
			if(f(t, i, i))
				res[t]++;
	}

	printf("%s\n", res[0]<res[1]? "네 다음 힐딱이" : "그만 알아보자");
	return 0;
}
