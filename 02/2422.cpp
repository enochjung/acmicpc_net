#include <cstdio>
#define N 201

int main() {
	int n, m;
	bool ban[N][N] = {};

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ban[a][b] = ban[b][a] = true;
	}

	int res = 0;
	for (int i=1; i<=n; ++i)
		for (int j=i+1; j<=n; ++j)
		{
			if (ban[i][j])
				continue;
			for (int k=j+1; k<=n; ++k)
				if (!ban[i][k] && !ban[j][k])
					++res;
		}
	printf("%d", res);
	return 0;
}