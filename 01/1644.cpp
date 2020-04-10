#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int n;
bool che[4000010];
vector<int> prime;
int a, b, sum, res;

int main()
{
	scanf("%d", &n);
	
	int len = sqrt(n);
	for(int i=2; i<=len; i++)
		if(!che[i])
			for(int j=i*2; j<=n; j+=i)
				che[j] = true;

	for(int i=2; i<=n; i++)
		if(!che[i])
			prime.push_back(i);
	prime.push_back(9999999);

	do
	{
		if(sum == n) res++;
		if(sum < n) sum += prime[b++];
		else sum -= prime[a++];
	} while(a < b);
	
	printf("%d", res);
}
