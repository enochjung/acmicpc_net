#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1510

using namespace std;

int n, d[N][N];
char s[N];

int f(int p, int q)
{
	if(p == q)
		return 0;
	if(d[p][q] == -1)
	{
		d[p][q] = 0;
		char t = (q-p)%3==0? 'B' : (q-p)%3==2? 'L' : 'D';
		if(s[p] == t)
			d[p][q] = max(d[p][q], 1+f(p+1,q));
		if(s[q-1] == t)
			d[p][q] = max(d[p][q], 1+f(p,q-1));
	}
	return d[p][q];
}

int main()
{
	memset(d, -1, sizeof(d));
	scanf("%d %s", &n, s);
	printf("%d", f(0, n*3));
	return 0;
}
