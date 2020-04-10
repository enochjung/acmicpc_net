#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, a[10010];
int sum;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	scanf("%d", &m);
	
	sort(a, a+n);
	for(int i=0; i<n; i++) {
		if(m < sum+a[i]*(n-i))
			return printf("%d", (m-sum)/(n-i));
		sum += a[i];
	}
	printf("%d", a[n-1]);
}
