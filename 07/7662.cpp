#include <stdio.h>
#include <set>

using namespace std;

int t, k;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		multiset<int> ms;

		scanf("%d", &k);
		while(k--)
		{
			char a;
			int b;
			scanf(" %c %d", &a, &b);

			if(a == 'I')
				ms.insert(b);
			else if(!ms.empty())
			{
				if(b == -1) {
					auto iter = ms.begin();
					ms.erase(iter);
				}
				else
				{
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}

		if(ms.empty())
			printf("EMPTY\n");
		else
		{
			auto iter = ms.begin();
			printf("%d ", *iter);
			iter = ms.end();
			iter--;
			printf("%d\n", *iter);
		}
	}
	return 0;
}
