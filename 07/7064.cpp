#include <cstdio>

int t, v, e;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int num[130] = {};
		bool street[130][130] = {};
		int res = 1;

		scanf("%d %d", &v, &e);
		for(int i=0; i<e; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			num[a]++, num[b]++;
			street[a][b] = street[b][a] = true;
		}

		for(int i=0; i<v; i++)
			if(num[i] > 2)
			{
				for(int j=0; j<v && num[i]>2; j++)
					if(num[j]>2 && street[i][j])
					{
						num[i]--, num[j]--;
						street[i][j] = street[j][i] = false;
						res++;
					}
				for(int j=0; j<v && num[i]>2; j++)
					if(street[i][j])
					{
						num[i]--, num[j]--;
						street[i][j] = street[j][i] = false;
						res++;
					}
			}
	
		printf("%d\n", res);
	}

	return 0;
}
