#include <cstdio>
#define N 200010

int n, a[N], cnt[N], res[N];

void f(int x)
{
	res[x] = 1;
	if(res[a[x]] == 0)
	{
		res[a[x]] = -1;
		if(--cnt[a[a[x]]] == 0)
			f(a[a[x]]);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n*2; ++i)
	{
		scanf("%d", a+i);
		++cnt[--a[i]];
	}

	for(int i=0; i<n*2; ++i)
		if(cnt[i] == 0)
			f(i);

	for(int i=0; i<n; ++i)
		if(res[i] >= 0)
			printf("%d ", i+1);
	for(int i=n; i<n*2; ++i)
		if(res[i] > 0)
			printf("%d ", i+1);
	return 0;
}
