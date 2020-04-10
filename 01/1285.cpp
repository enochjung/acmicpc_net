#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[30];

int f(int lv)
{
	if(lv < n)
	{
		int res1, res2;

		res1 = f(lv+1);
		a[lv] = ~a[lv];
		res2 = f(lv+1);

		return min(res1, res2);
	}

	int res = 0;
	for(int j=1; j<(1<<n); j<<=1)
	{
		int sum = 0;
		for(int i=0; i<n; i++)
			sum += (a[i]&j) > 0;
		res += min(sum, n-sum);
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=1; j<(1<<n); j<<=1)
		{
			char c;
			scanf(" %c", &c);
			a[i] |= (c=='H'? j : 0);
		}

	printf("%d\n", f(0));
	return 0;
}
