#include <stdio.h>
#include <math.h>

long long min, max;
bool che[1000010], a[1000010];
int res;

int main()
{
	scanf("%lld %lld", &min, &max);
	
	for(int i=2; i<=1000; i++)
		if(!che[i])
			for(int j=i*2; j<=1000000; j+=i)
				che[j] = true;

	for(int i=2; i<=1000000; i++)
		if(!che[i]) {
			long long n = 1LL*i*i;
			for(long long j=(min+n-1)/n*n-min; j<=max-min; j+=n)
				a[j] = true;
		}

	for(int i=0; i<=max-min; i++)
		if(!a[i])
			res++;

	printf("%d", res);
}
