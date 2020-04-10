#include <cstdio>
#include <cstdlib>

int n;
char s[20], t[20];

bool f()
{
	int a[26]={}, b[26]={};
	int as, bs;

	for(as=0; s[as]; as++)
		a[s[as]-'A']++;
	for(bs=0; t[bs]; bs++)
		b[t[bs]-'A']++;

	int dif = 0;
	for(int i=0; i<26; i++)
		dif += abs(a[i]-b[i]);

	return dif<2 || (dif==2 && as==bs);
}

int main()
{
	scanf("%d %s", &n, s);

	int cnt = 0;
	for(int i=0; i<n-1; i++)
	{
		scanf("%s", t);
		if(f())
			cnt++;
	}

	printf("%d", cnt);
	return 0;
}
