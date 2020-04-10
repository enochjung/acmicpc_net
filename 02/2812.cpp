#include <cstdio>
#include <queue>
#define N 500010

using namespace std;

struct st
{
	int i;
	char c;
	bool operator<(const st &hs) const
	{
		return !(c!=hs.c? c>hs.c : i<hs.i);
	}
};

int n, k;
char s[N];
priority_queue<st> pq;

int main()
{
	scanf("%d %d %s", &n, &k, s);

	for(int i=0; i<k; ++i)
		pq.push({i, s[i]});

	int l = 0;
	for(int i=k; i<n; ++i)
	{
		pq.push({i, s[i]});
		while(pq.top().i < l)
			pq.pop();
		printf("%c", pq.top().c);
		l = pq.top().i+1;
		pq.pop();
	}

	return 0;
}
