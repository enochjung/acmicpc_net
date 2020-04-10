#include <cstdio>

char a[100010];
int res;

int main()
{
	scanf("%s", a);

	int cnt = 0;
	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
		{
			if(a[i+1] == ')')
			{
				res += cnt;
				i++;
			}
			else
				cnt++;
		}
		else
		{
			res++;
			cnt--;
		}
	}

	printf("%d\n", res);
	return 0;
}
