#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 60

using namespace std;

int n, m;
char a[N], b[N];

int f(int x)
{
	int cnt = 0;
	for(int i=0; i<n; ++i)
		if(a[i] != b[i+x])
			++cnt;
	return cnt;
}

int main()
{
	scanf("%s %s", a, b);
	n = (int)strlen(a);
	m = (int)strlen(b);

	int res = 99;
	for(int i=0; i<=m-n; ++i)
		res = min(res, f(i));
	printf("%d", res);
	return 0;
}
