#include <stdio.h>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int check[50001], check2[50001], ch[50001];
vector<int> r[50001], r2[50001];
stack<int> S, S2;
set<int> out[50001];

void dfs(int x) {
	check[x] = 1;
	for (auto it = r[x].begin(); it != r[x].end(); it++)
		if (check[*it] == 0) dfs(*it);
	S.push(x);
}

void dfs2(int x, int w) {
	check2[x] = 1;
	for (auto it = r2[x].begin(); it != r2[x].end(); it++)
		if (check2[*it] == 0) dfs2(*it, w);
	out[w].insert(x);
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	while (1)
	{
		int x, y, m;
		int n, out_len=0;
		memset(check, 0, sizeof(check));
		memset(check2, 0, sizeof(check2));
		memset(ch, 0, sizeof(ch));
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= m; i++) 
		{
			scanf("%d %d", &x, &y);
			ch[x] = 1;
			r[x].push_back(y), r2[y].push_back(x);
		}

		for (int i = 1; i <= n; i++)
			if (check[i] == 0) dfs(i);
		while (!S.empty()) {
			int x = S.top();

			S.pop();
			if (check2[x]) continue;

			dfs2(x, ++out_len);
		}
		sort(out + 1, out + out_len + 1);
		int p = 1;
		for (int i = 1; i <= out_len; i++)
		{
			int q = 0;
			for (auto it = out[i].begin(); it != out[i].end(); it++, q++);
			if (q == 1)
			{
				auto it = out[i].begin();
				if (ch[*it] ==1 )
				{
					p = 0;
					break;
				}
			}
		}
		if (p == 0)
			printf("N\n");
		else
			printf("Y\n");
		for (int i = 1; i <= n; i++)
		{
			r[i].clear();
			r2[i].clear();
		}
	}
}

