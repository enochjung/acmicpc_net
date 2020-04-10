#include <cstdio>

int n, k;
int num, val, cnt;

int main()
{
	scanf("%d %d", &n, &k);

	for(num=1,val=9; k>num*val; num++,val*=10)
	{
		k -= num*val;
		n -= val;
	}

	k--;
	cnt += k/num;
	k %= num;
	n -= cnt;

	val = val/9+cnt;
	for(int i=0; i<num-k-1; i++)
		val /= 10;

	printf("%d\n", n>0? val%10 : -1);
	return 0;
}
