#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 999

using namespace std;

int n, k;
int a[110][110];
bool visited[110];
vector<int> res;

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			a[i][j] = (i==j? 0 : INF);

	for(int i=0; i<k; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		p--, q--;
		a[p][q] = a[q][p] = 1;
	}

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(a[i][k]+a[k][j] < a[i][j])
					a[i][j] = a[i][k]+a[k][j];

	for(int k=0; k<n; k++)
		if(!visited[k])
		{
			int min_len=INF, idx=0;
			vector<int> group;
			
			for(int i=k; i<n; i++)
				if(a[k][i] != INF) {
					group.push_back(i);
					visited[i] = true;
				}
			
			for(int i=0; i<(int)group.size(); i++)
			{
				int len = 0;
				for(int j=0; j<(int)group.size(); j++)
					len = max(len, a[group[i]][group[j]]);
				
				if(len < min_len) {
					min_len = len;
					idx = group[i];
				}
			}

			res.push_back(idx);
		}

	sort(res.begin(), res.end());
	printf("%d\n", (int)res.size());
	for(int i=0; i<(int)res.size(); i++)
		printf("%d\n", res[i]+1);
}
