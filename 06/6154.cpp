#include <cstdio>
#include <stack>
#define N 100010

using namespace std;

int n, w[N], h[N], st;
long long res[N];
stack<int> s;

int main()
{
	scanf("%d", &n);
	
	h[0] = h[n+1] = 9999999;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d %d", w+i, h+i);
		if(h[i] < h[st])
			st = i;
	}
	
	int l=st, r=st;
	long long sum = 0;
	for(int i=st; 1<=i && i<=n;)
	{
		s.push(i);
		i = h[l-1]<h[r+1]? --l : ++r;
		while(!s.empty() && h[s.top()]<h[i])
		{
			int j = s.top();
			s.pop();
			int k = !s.empty() && h[s.top()]<h[i]? s.top() : i;

			res[j] = sum+w[j];
			w[k] += w[j];
			sum += 1LL*w[j]*(h[k]-h[j]);
		}
	}

	for(int i=1; i<=n; ++i)
		printf("%lld\n", res[i]);
	return 0;
}