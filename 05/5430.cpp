#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int t, n;
char p[100010];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		deque<int> dq;

		scanf("%s %d", p, &n);
		getchar();
		getchar();
		for(int i=0; i<n; i++)
		{
			int v;
			scanf("%d,", &v);
			dq.push_back(v);
		}
		getchar();

		bool r = false;
		bool success = true;
		for(int i=0; p[i]; i++)
		{
			if(p[i] == 'R')
				r = !r;
			else
			{
				if(dq.empty())
				{
					printf("error\n");
					success = false;
					break;
				}
				if(!r)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if(success)
		{
			if(r)
				reverse(dq.begin(), dq.end());

			printf("[");
			while(!dq.empty())
			{
				printf("%d", dq.front());
				dq.pop_front();
				if(!dq.empty())
					printf(",");
			}
			printf("]\n");
		}
	}
	return 0;
}
