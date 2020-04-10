#include <cstdio>
#include <cstring>

int n;

int main()
{
	int tot = 0;
	int val = 0;
	char name[30];

	scanf("%d", &n);
	while(n--)
	{
		char s[30];
		int k, m;
		scanf("%s %d %d", s, &k, &m);

		int num = (m-2)/(k-2);
		if(val < num)
		{
			val = num;
			strcpy(name, s);
		}
		tot += (m-2)/(k-2);
	}

	printf("%d\n%s", tot, name);
	return 0;
}
