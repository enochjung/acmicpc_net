#include <cstdio>

int n, cnt;

bool f(char* s)
{
	int t;
	bool v[26] = {};

	t = s[0]-'a';
	v[t] = true;

	for(int i=1; s[i]; i++)
		if(s[i]-'a' != t)
		{
			t = s[i]-'a';
			if(v[t])
				return false;
			v[t] = true;
		}

	return true;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		char s[110] = {};
		scanf("%s", s);
		if(f(s))
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
