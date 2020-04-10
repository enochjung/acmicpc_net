#include <cstdio>

char s[110];

bool is_pal(int a, int b)
{
	for(int i=0; a+i<b-i; ++i)
		if(s[a+i] != s[b-i])
			return false;
	return true;
}

bool is_odd()
{
	for(int i=0; s[i]; ++i)
		for(int j=i; s[j]; ++j)
			if(is_pal(i, j) && (j-i)%2)
					return false;
	return true;
}

int main()
{
	scanf("%s", s);
	printf("%s", is_odd()? "Odd." : "Or not.");
	return 0;
}
