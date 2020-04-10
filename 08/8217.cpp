#include <cstdio>
#include <cstring>
#include <vector>
#define N 300010

using namespace std;

int n, m, k, p[N], l[N], r[N], a[N];
int lo[N], hi[N], res[N];
vector<int> o[N], mid[N];
long long t[N];

void add(int idx, int val)
{
	while(idx)
	{
		t[idx] += val;
		idx -= idx&-idx;
	}
}

long long get(int idx)
{
	long long sum = 0;
	while(idx <= m)
	{
		sum += t[idx];
		idx += idx&-idx;
	}
	return sum;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int v;
		scanf("%d", &v);
		o[v-1].push_back(i+1);
	}
	for(int i=0; i<n; ++i)
		scanf("%d", p+i);
	scanf("%d", &k);
	for(int i=0; i<k; ++i)
		scanf("%d %d %d", l+i, r+i, a+i);

	for(int i=0; i<n; ++i)
	{
		lo[i] = 0;
		hi[i] = k-1;
		res[i] = k;
	}
	while(1)
	{
		bool flag = false;
		for(int i=0; i<n; ++i)
			if(lo[i] <= hi[i])
			{
				flag = true;
				mid[(lo[i]+hi[i])/2].push_back(i);
			}
		if(!flag)
			break;

		memset(t, 0, sizeof(t));
		for(int i=0; i<k; ++i)
		{
			add(l[i]-1, -a[i]);
			add(r[i], a[i]);
			if(l[i] > r[i])
				add(m, a[i]);

			for(int now : mid[i])
			{
				long long sum = 0;
				for(int tar : o[now])
				{
					sum += get(tar);
					if(sum >= p[now])
						break;
				}
				
				if(sum >= p[now])
				{
					res[now] = i;
					hi[now] = i-1;
				}
				else
					lo[now] = i+1;
			}
			mid[i].clear();
		}
	}

	for(int i=0; i<n; ++i)
	{
		if(res[i] < k)
			printf("%d\n", res[i]+1);
		else
			printf("NIE\n");
	}
	return 0;
}
