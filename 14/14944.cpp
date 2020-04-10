#include <cstdio>
#include <algorithm>
#define N 10010
#define INF 999999999

using namespace std;

int n, m, l[N], s[N];
int res;

int d(int a, int b)
{
	return s[b]-s[a];
}

int f(int a, int b, int c)
{
	return min(
			{
			b-a==1? d(0,a)+c+d(b,n) : INF,
			d(0,b)+c+d(a,n),
			d(0,a)+c+d(b,n)+d(a+1,n),
			d(0,a)+c+d(b,n)+d(b,n)+c+d(a,b-1),
			d(0,n)+c*2
			});
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", l+i);

	for(int i=1; i<=n; ++i)
		s[i] = s[i-1]+l[i-1];

	res = INF;
	while(m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		res = min(res, f(min(a,b),max(a,b),c));
	}

	printf("%d", res);
	return 0;
}
