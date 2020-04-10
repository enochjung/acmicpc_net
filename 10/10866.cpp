#include <cstdio>
#include <queue>

using namespace std;

int n;
deque<int> dq;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		char s[20];
		scanf("%s", s);

		switch(s[1])
		{
		case 'u':
			int v;
			scanf("%d", &v);

			if(s[5] == 'f')
				dq.push_front(v);
			else
				dq.push_back(v);
			break;

		case 'o':
			if(dq.empty())
				printf("-1\n");
			else if(s[4] == 'f')
			{
				printf("%d\n", dq.front());
				dq.pop_front();
			}
			else
			{
				printf("%d\n", dq.back());
				dq.pop_back();
			}
			break;

		case 'i':
			printf("%d\n", (int)dq.size());
			break;

		case 'm':
			printf("%d\n", dq.empty());
			break;

		case 'r':
			printf("%d\n", dq.empty()? -1 : dq.front());
			break;

		case 'a':
			printf("%d\n", dq.empty()? -1 : dq.back());
			break;
		}
	}
	return 0;
}
