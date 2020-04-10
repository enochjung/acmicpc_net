#include <cstdio>

int t, n, f[510], a[3];

int abs(int x)
{
	return x>0? x : -x;
}

int sum(int idx, int d)
{
	int s = 0;
	for(int i=idx; i<idx+d; ++i)
		s += f[i]*a[i-idx];
	return s;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%d", f+i);

		a[0] = f[1]/f[0];
		a[1] = (f[2]-a[0]*f[1])/f[0];
		a[2] = (f[3]-a[1]*f[2]-a[0]*f[1])/f[0];

		for(int d=1; d<=3; ++d)
		{
			bool flag = true;
			for(int i=d; i<n; ++i)
				if(sum(i-d,d) != f[i])
				{
					flag = false;
					break;
				}
			if(!flag || abs(sum(n-d,d)>100000))
				continue;
			printf("%d\n", sum(n-d,d));
			break;
		}
	}
	return 0;
}
