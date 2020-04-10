#include <cstdio>
#define N 500010

using namespace std;

int n, s[N];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		int v;
		scanf("%d", &v);
		s[i] = s[i-1]+v;
	}
}
