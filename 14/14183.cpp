#include <stdio.h>

int m, n, a[20], b[20];

int main()
{
	while(1)
	{
		scanf("%d %d", &m, &n);
		if(m == 0) break;
		
		for(int i=0; i<m; i++)
			scanf("%d", a+i);

		int res = 0;
		while(n--)
		{
			bool success = true;
			for(int i=0; i<m; i++)
				scanf("%d", b+i);

			for(int i=0; i<m; i++)
				if(b[i] > a[i])
				{
					success = false;
					break;
				}

			if(success)
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
