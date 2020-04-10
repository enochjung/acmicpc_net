#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[100010];

long long f(int x, int y)
{
	if(x+1 == y)
		return a[x]*a[x];

	int m = (x+y)/2;
	int mini = a[m];
	long long sum = a[m];
	long long res = mini*sum;

	for(int i=m,j=m+1; x<i || j<y;)
	{
		if(i==x || (j<y && a[i-1]<a[j]))
		{
			mini = min(mini, a[j]);
			sum += a[j];
			res = max(res, mini*sum);
			j++;
		}
		else
		{
			i--;
			mini = min(mini, a[i]);
			sum += a[i];
			res = max(res, mini*sum);
		}
	}
	
	res = max(res, f(x,m));
	res = max(res, f(m,y));

	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	printf("%lld\n", f(0,n));
	return 0;
}
