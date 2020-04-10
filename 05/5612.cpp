#include <cstdio>

int n, m, res;

int main()
{
	scanf("%d %d", &n, &m);
	res = m<0? -1 : m;
	while(n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		m += a-b;
		if(m < 0)
			res = -1;
		else if(res!=-1 && res<m)
			res = m;
	}
	printf("%d", res>0? res : 0);
	return 0;
}
