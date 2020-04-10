#include <stdio.h>
#include <string.h>
#include <vector>
#define N 200010

using namespace std;

int n, q[N*2], v[N];
vector<pair<int,int>> e[N];

bool f(int x, int lv, int value)
{
	v[x] = lv;

	for(auto i : e[x])
	{
		int to = i.first;
		int w = i.second;
		if(w<=value && (q[to]==-1 || (v[q[to]]<lv && f(q[to],lv,value))))
		{
			q[to] = x;
			return true;
		}
	}
	return false;
}

bool match(int value)
{
	memset(q, -1, sizeof(q));
	memset(v, -1, sizeof(v));

	for(int i=0; i<n; i++)
		if(!f(i, i, value))
			return false;

	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		e[i].push_back({a-1, b});
		e[i].push_back({c-1, d});
	}

	int left=0, right=1000000000;
	int res=-1;
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(match(mid))
		{
			right = mid-1;
			res = mid;
		}
		else
			left = mid+1;
	}

	printf("%d\n", res);
	return 0;
}
