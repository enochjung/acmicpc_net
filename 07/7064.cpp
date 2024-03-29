#include <cstdio>
#include <vector>

class bipartite_matching {
private:
	int n;
	std::vector<std::vector<int>> edge;
	std::vector<int> visited, matched;

	bool dfs(int x, int lv) {
		visited[x] = lv;
		for (int target : edge[x]) {
			if (matched[target]==-1 || (visited[matched[target]]<lv && dfs(matched[target],lv))) {
				matched[target] = x;
				return true;
			}
		}
		return false;
	}

public:
	bipartite_matching(int n) : n(n) {
		edge.resize(n);
		visited.resize(n, -1);
		matched.resize(n, -1);
	}

	void add_edge(int a, int b) {
		edge[a].push_back(b);
	}

	int match() {
		int count = 0;
		for (int i=0; i<n; ++i) {
			if (dfs(i, i))
				++count;
		}
		return count;
	}
};

int main() {
	int data_set;

	scanf("%d", &data_set);
	for (int test_case=1; test_case<=data_set; ++test_case) {
		int no_of_intersections;
		int no_of_streets;

		scanf("%d %d", &no_of_intersections, &no_of_streets);
		bipartite_matching bm(no_of_intersections);

		for (int i=0; i<no_of_streets; ++i) {
			int s, e;
			scanf("%d %d", &s, &e);
			bm.add_edge(s-1, e-1);
		}

		printf("%d\n", no_of_intersections - bm.match());
	}

	return 0;
}
