#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[30];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	double avg = a[0];
	for(int i=1; i<n; ++i)
		avg = (avg+a[i])/2;

	printf("%.6lf", avg);
	return 0;
}
