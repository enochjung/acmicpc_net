#include <cstdio>
#include <algorithm>
#define N 200010

using namespace std;

int n;
char s[N];
int t, sa[N], g[N], lcp[N];

bool compare(int i, int j)
{
	return g[i]!=g[j]? g[i]<g[j] : (i+t<n && j+t<n? g[i+t]<g[j+t] : i>j);
}

void suffix_array()
{
	for(int i=0; i<n; ++i)
	{
		sa[i] = i;
		g[i] = s[i]-'a';
	}
	for(t=1; t<=n; t<<=1)
	{
		int tmp[N] = {};

		sort(sa, sa+n, compare);
		for(int i=0; i<n-1; ++i)
			tmp[i+1] = tmp[i]+compare(sa[i], sa[i+1]);
		for(int i=0; i<n; ++i)
			g[sa[i]] = tmp[i];
	}
}

void longest_common_prefix()
{
	for(int i=0,k=0; i<n; ++i)
	{
		if(g[i] == n-1)
			continue;
		for(int j=sa[g[i]+1]; s[i+k]==s[j+k]; ++k);
		lcp[g[i]] = k;
		k = max(0, k-1);
	}
}

int main()
{
	scanf("%d %s", &n, s);
	suffix_array();
	longest_common_prefix();
	
	int res = 0;
	for(int i=0; i<n-1; ++i)
		res = max(res, lcp[i]);
	printf("%d", res);
	return 0;
}
