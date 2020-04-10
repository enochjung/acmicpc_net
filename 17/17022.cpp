#include <cstdio>
#include <stack>
#define N 100010

using namespace std;

int n, a[N], b[N];
stack<int> s;

void update(int idx, int val)
{
	while(idx <= n)
	{
		b[idx] += val;
		idx += idx&-idx;
	}
}

int get(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += b[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int k;
	for(k=n-2; k>=0 && a[k]<a[k+1]; --k);

	for(int i=1; i<=n; ++i)
		update(i, 1);
	for(int i=k; i>=0; --i)
	{
		update(a[i], -1);
		s.push(get(a[i])+k-i);
	}

	printf("%d\n", (int)s.size());
	while(!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}
