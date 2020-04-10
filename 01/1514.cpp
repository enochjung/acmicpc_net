#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 110

using namespace std;

struct st
{
	int i, j, k, w;
};

int n, a[N], b[N];
int d[N][10][10][10];
bool v[N][10][10][10];
int res;
queue<st> q;

void update(int i, int j, int k, int w, int p)
{
	if(d[i][j][k][w] == -1)
	{
		q.push({i, j, k, w});
		d[i][j][k][w] = p;
	}
	d[i][j][k][w] = min(d[i][j][k][w], p);
	if(i == n)
		res = min(res, p);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%1d", a+i);
	for(int i=0; i<n; ++i)
	{
		scanf("%1d", b+i);
		b[i] = (b[i]-a[i]+10)%10;
	}

	res = 999;
	memset(d, -1, sizeof(d));
	d[0][0][0][0] = 0;
	q.push({0, 0, 0, 0});
	while(!q.empty())
	{
		st now = q.front();
		q.pop();
		int i = now.i;
		int j = now.j;
		int k = now.k;
		int w = now.w;

		if(i>=n || v[i][j][k][w])
			continue;
		v[i][j][k][w] = true;

		if((b[i]+j)%10 == 0)
			update(i+1, k, w, 0, d[i][j][k][w]);
		else
			for(int t=7; t<=13; ++t)
				if(t != 10)
				{
					update(i, (j+t)%10, k, w, d[i][j][k][w]+1);
					update(i, (j+t)%10, (k+t)%10, w, d[i][j][k][w]+1);
					update(i, (j+t)%10, (k+t)%10, (w+t)%10, d[i][j][k][w]+1);
				}
	}

	printf("%d", res);
	return 0;
}
