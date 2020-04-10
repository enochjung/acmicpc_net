#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100010

using namespace std;

int n, d, v[N];
long long t[N];
vector<int> p;

long long f(int i, int j)
{
	return t[j]*(j-i)+v[i];
}

bool check(int i, int j, int k)
{
	return (t[k]*k-t[i]*i)*(t[j]-t[i]) <= (t[j]*j-t[i]*i)*(t[k]-t[i]);
}

int main()
{
	scanf("%d %d", &n, &d);
	for(int i=0; i<n; ++i)
		scanf("%lld", t+i);
	for(int i=0; i<n; ++i)
		scanf("%d", v+i);

	long long res = 0;
	int k = 0;
	for(int i=0,j=0; i<n; ++i)
	{
		for(; k<n && k<=i+d; ++k)
		{
			for(int b=p.size()-1; !p.empty() && (t[p[b]]*p[b]<=t[k]*k || (b && check(p[b-1],p[b],k))); --b)
				p.pop_back();
			p.push_back(k);
		}
		j = min(j, (int)p.size()-1);
		while(p[j]<i || (j<(int)p.size()-1 && f(i,p[j])<=f(i,p[j+1])))
			++j;
		res = max(res, f(i,p[j]));
	}

	printf("%lld", res);
	return 0;
}
