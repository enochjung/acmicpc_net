#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#define N 1010
#define M 30

using namespace std;

int n, m, p[M][2], cnt[M], d[M][2];
char str[N];
map<char,int> ctoi;
set<char> s;

int main()
{
	scanf("%s", str);

	for(; str[n]; ++n)
		s.insert(str[n]);
	for(char c : s)
		ctoi[c] = 1+m++;
	for(int i=1; i<=m; ++i)
		p[i][0] = 9999;

	for(int i=0; i<n; ++i)
	{
		int idx = ctoi[str[i]];
		++cnt[idx];
		p[idx][0] = min(p[idx][0], i);
		p[idx][1] = max(p[idx][1], i);
	}

	for(int i=1; i<=m; ++i)
	{
		d[i][0] = min(d[i-1][0]+abs(p[i-1][0]-p[i][1]),d[i-1][1]+abs(p[i-1][1]-p[i][1]))+p[i][1]-p[i][0]+cnt[i];
		d[i][1] = min(d[i-1][0]+abs(p[i-1][0]-p[i][0]),d[i-1][1]+abs(p[i-1][1]-p[i][0]))+p[i][1]-p[i][0]+cnt[i];
	}

	printf("%d", min(d[m][0], d[m][1]));
	return 0;
}
