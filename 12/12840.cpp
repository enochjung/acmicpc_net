#include <cstdio>
#define R 86400

int h, m, s, t;

int main()
{
	scanf("%d %d %d %d", &h, &m, &s, &t);
	s += m*60+h*3600;
	while(t--)
	{
		int a, b;
		scanf("%d", &a);
		if(a == 1)
		{
			scanf("%d", &b);
			s = (s+b)%R;
		}
		else if(a == 2)
		{
			scanf("%d", &b);
			s = ((s-b)%R+R)%R;
		}
		else
			printf("%d %d %d\n", s/3600, s%3600/60, s%60);
	}
	return 0;
}
