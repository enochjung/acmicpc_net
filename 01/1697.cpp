#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, k;
int d[100010];
queue<int> q;

int main()
{
	scanf("%d %d", &n, &k);

	memset(d, -1, sizeof(d));
	d[n] = 0;
	q.push(n);

	while(!q.empty())
	{
		int p = q.front();
		q.pop();

		if(p == k)
			break;

		if(0<=p-1 && d[p-1]==-1)
		{
			d[p-1] = d[p]+1;
			q.push(p-1);
		}
		if(p+1<=100000 && d[p+1]==-1)
		{
			d[p+1] = d[p]+1;
			q.push(p+1);
		}
		if(p*2<=100000 && d[p*2]==-1)
		{
			d[p*2] = d[p]+1;
			q.push(p*2);
		}
	}

	printf("%d\n", d[k]);
	return 0;
}
