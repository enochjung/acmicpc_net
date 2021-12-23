#include <cstdio>
#include <string>
#include <map>
#define N 200
#define INF 999

using namespace std;

int n, m, l;
map<string,int> idx;
int d[N][N];

int get_idx(char* name)
{
	string str(name);
	if (idx.find(str) == idx.end())
		idx.insert({str, l++});
	return idx[str];
}

int main()
{
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			d[i][j] = i==j? 0 : INF;

	scanf("%d %d", &n, &m);
	while (n--)
	{
		char a[31], b[31];
		scanf(" %s are worse than %s", a, b);
		int ai = get_idx(a);
		int bi = get_idx(b);
		d[ai][bi] = 1;
	}

	for (int k=0; k<l; ++k)
		for (int i=0; i<l; ++i)
			for (int j=0; j<l; ++j)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	while (m--)
	{
		char a[31], b[31];
		scanf(" %s are worse than %s", a, b);
		int ai = get_idx(a);
		int bi = get_idx(b);

		if (d[ai][bi]!=INF && d[ai][bi]>0)
			printf("Fact\n");
		else if (d[bi][ai]!=INF && d[bi][ai]>0)
			printf("Alternative Fact\n");
		else
			printf("Pants on Fire\n");
	}

	return 0;
}