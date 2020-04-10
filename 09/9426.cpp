#include <cstdio>

int n, k, a[250010];
int t[131090];
long long res;

int get(int v)
{
	int x = 1;
	while(x < (1<<16))
	{
		if(v <= t[x*2])
			x *= 2;
		else
		{
			v -= t[x*2];
			x = x*2+1;
		}
	}
	return x-(1<<16);
}

void set(int x, int v)
{
	x += 1<<16;
	t[x] += v;
	for(; x>1; x/=2)
		t[x/2] = t[x]+t[x^1];
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	for(int i=0; i<k; i++)
		set(a[i], 1);
	res += get((k+1)/2);

	for(int i=0; i<n-k; i++)
	{
		set(a[i+k], 1);
		set(a[i], -1);
		res += get((k+1)/2);
	}
	printf("%lld\n", res);
	return 0;
}
