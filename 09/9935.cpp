#include <cstdio>
#include <cstring>
#define N 1000010

int l;
char s[N], c[40], a[N];

int main()
{
	scanf("%s %s", s, c);
	l = (int)strlen(c);

	for(int i=0,j=0; s[i]; ++i,++j)
	{
		a[j] = s[i];
		a[j+1] = 0;
		if(j-l+1>=0 && strcmp(a+j-l+1,c)==0)
		{
			j -= l;
			a[j+1] = 0;
		}
	}
	
	printf("%s", a[0]? a : "FRULA");
	return 0;
}
