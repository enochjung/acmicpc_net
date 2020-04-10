#include <cstdio>

int n, a[60];
bool visited[60];

void f(int x)
{
	visited[x] = true;
	if(!visited[a[x]])
		f(a[x]);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int cnt = 0;
	for(int i=0; i<n; ++i)
		if(!visited[i])
		{
			++cnt;
			f(i);
		}

	printf("%d", cnt>1? cnt : 0);
	return 0;
}
