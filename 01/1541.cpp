#include <cstdio>
#define N 60

char s[N];

int get(int &i)
{
	int ret = 0;

	for(; '0'<=s[i] && s[i]<='9'; ++i)
	{
		ret *= 10;
		ret += s[i]-'0';
	}
	
	return ret;
}

int main()
{
	scanf("%s", s);

	bool minus = false;
	int res = 0;
	for(int i=0; s[i]; ++i)
	{
		res += minus? -get(i) : get(i);
		if(s[i] == '-')
			minus = true;
	}
	printf("%d", res);
	return 0;
}
