#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1000
#define K 30000
#define INF 99999999

struct road {
	int to, cost;
};

int n, m, k;
int s, d;
std::vector<road> edge[N]; 
int p[K];
int dp[N][N]; // dp[a][b] = 시작 도시 S에서 b개 이하의 도로를 사용해 도시 a로 갈 때의 최소 비용

int f(int a, int b) {
	if (a == s)
		return 0;
	if (b == 0)
		return INF;
	if (dp[a][b] == -1) {
		dp[a][b] = f(a, b-1);
		for (road r : edge[a])
			dp[a][b] = std::min(dp[a][b], f(r.to,b-1)+r.cost);
	}
	return dp[a][b];
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &s, &d);
	--s, --d;
	for (int i=0; i<m; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		--a, --b;
		edge[a].push_back({b, w});
		edge[b].push_back({a, w});
	}
	for (int i=0; i<k; ++i)
		scanf("%d", p+i);

	memset(dp, -1, sizeof(dp));

	int cost_sum = 0;
	for (int i=0; i<=k; ++i) {
		int result = INF;
		for (int j=0; j<n; ++j)
			result = std::min(result, f(d,j)+cost_sum*j);
		printf("%d\n", result);
		if (i == k)
			break;
		cost_sum += p[i];
	}

	return 0;
}