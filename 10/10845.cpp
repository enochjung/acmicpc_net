#include <cstdio>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		char s[10];
		scanf("%s", s);

		switch(s[1])
		{
		case 'u':
			int v;
			scanf("%d", &v);
			q.push(v);
			break;

		case 'o':
			if(q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
			break;

		case 'i':
			printf("%d\n", (int)q.size());
			break;

		case 'm':
			printf("%d\n", q.empty());
			break;

		case 'r':
			printf("%d\n", q.empty()? -1 : q.front());
			break;

		case 'a':
			printf("%d\n", q.empty()? -1 : q.back());
			break;
		}
	}

}
