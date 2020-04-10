#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1010
#define M 60

using namespace std;

struct st
{
	int i, c;
	bool operator<(const st &hs) const
	{
		return c!=hs.c? c>hs.c : i<hs.i;
	}
};

int n, m;
char a[N][M], s[M];
vector<st> b[M];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%s", a[i]);

	for(int j=0; j<m; ++j)
		for(int k=0; k<26; ++k)
			b[j].push_back({k, 0});
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			++b[j][a[i][j]-'A'].c;

	int res = 0;
	for(int j=0; j<m; ++j)
	{
		sort(b[j].begin(), b[j].end());
		s[j] = b[j][0].i+'A';
		res += n-b[j][0].c;
	}
	printf("%s\n%d", s, res);
	return 0;
}
