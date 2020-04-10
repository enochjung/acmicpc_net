#include <cstdio>
#define N 1000010

int n;
char s[N];

int kmp()
{
	int fail[N] = {};

	for(int i=1,j=0; i<n; ++i)
	{
		while(j && s[i]!=s[j])
			j = fail[j-1];
		if(s[i] == s[j])
			fail[i] = ++j;
	}
	for(int i=1,j=0; i<n*2; ++i)
	{
		while(j && s[i%n]!=s[j])
			j = fail[j-1];
		if(s[i%n] == s[j])
		{
			if(j == n-1)
				return i-n+1;
			++j;
		}
	}
	return n;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf(" %c", s+i);
	scanf("%*[^\n]s");

	printf("1/%d", kmp());
	return 0;
}
