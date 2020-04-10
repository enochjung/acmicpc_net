#include <cstdio>
#include <cstring>

int n;
char a[20], b[30];

int main()
{
	scanf("%s %d", a, &n);

	int res = 0;
	while(n--)
	{
		scanf("%s", b);
		strcat(b, b);
		if(strstr(b, a) != nullptr)
			++res;
	}
	printf("%d", res);
	return 0;
}
