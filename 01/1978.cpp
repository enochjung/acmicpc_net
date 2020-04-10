#include <cstdio>

int n;
int res;
bool np[1010] = {1, 1};

int main()
{
	for(int i=2; i*i<=1000; i++)
		if(!np[i])
			for(int j=i*2; j<=1000; j+=i)
				np[j] = true;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int v;
		scanf("%d", &v);
		res += !np[v];
	}
	printf("%d\n", res);
	return 0;
}
