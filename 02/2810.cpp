#include <cstdio>
#include <algorithm>

using namespace std;

int n;
char s[60];

int main()
{
	scanf("%d %s", &n, s);

	int h = n+1;
	for(int i=0; s[i]; ++i)
		if(s[i] == 'L')
		{
			--h;
			++i;
		}
	printf("%d", min(h, n));
	return 0;
}
