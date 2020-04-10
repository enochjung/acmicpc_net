#include <cstdio>
#define N 5010
#define M 100010
#define R 1000000007

int n, m, k, s[N], c[N], e[26];
int d[N], p[N];

int pow(int a, int b)
{
	if(b == 1)
		return a;
	if(b%2 == 0)
	{
		int ret = pow(a, b/2);
		return 1LL*ret*ret%R;
	}
	return 1LL*a*pow(a, b-1)%R;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; ++i)
		scanf("%d %d", s+i, c+i);
	for(int i=0; i<m; ++i)
	{
		char v;
		scanf(" %c", &v);
		++e[v-'A'];
	}

	d[0] = 1;
	for(int i=0; i<k; ++i)
		for(int j=0; j<n; ++j)
			if(i+s[j] < k)
				d[i+s[j]] = (d[i+s[j]] + d[i])%R;
	for(int i=0; i<n; ++i)
		p[c[i]-1] = (p[c[i]-1] + (k-s[i]>=0? d[k-s[i]] : 0))%R;

	int res = 1;
	for(int i=0; i<26; ++i)
		if(e[i])
		{
			int sum = 0;
			for(int j=0; j<n; ++j)
				if(p[j])
					sum = (sum + pow(p[j], e[i]))%R;
			res = 1LL*res*sum%R;
		}
	printf("%d", res);
	return 0;
}
