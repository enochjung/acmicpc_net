#include <cstdio>
#include <memory>
#include <vector>
#define N 15
#define KX 15

class bipartite_matching {
   private:
    int n, m;
    std::vector<std::vector<int>> edge;
    std::vector<int> visited, matched;

    bool dfs(int x, int lv) {
        visited[x] = lv;
        for (int target : edge[x]) {
            if (matched[target] == -1 ||
                (visited[matched[target]] < lv && dfs(matched[target], lv))) {
                matched[target] = x;
                return true;
            }
        }
        return false;
    }

   public:
    bipartite_matching(int n, int m) : n(n), m(m) {
        edge.resize(n);
        visited.resize(n, -1);
        matched.resize(m, -1);
    }

    void add_edge(int a, int b) { edge[a].push_back(b); }

    std::vector<int> match() {
        for (int i = 0; i < n; ++i) dfs(i, i);
        return matched;
    }
};

struct applicant {
    int id, score;
    std::unique_ptr<std::vector<int>> group;
    bool operator<(const applicant &hs) const { return score > hs.score; }
};

int main() {
    int n, k, x;

    scanf("%d %d %d", &n, &k, &x);

    bipartite_matching bm(n, k * x);
    std::vector<applicant> a(n);

    for (int i = 0; i < n; ++i) {
        int num;
        a[i].id = i;
        a[i].group = std::make_unique<std::vector<int>>();
        scanf("%d", &num);
        while (num--) {
            int gid;
            scanf("%d", &gid);
            a[i].group->push_back(gid - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        int s;
        scanf("%d", &s);
        a[i].score = s;
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        for (int gid : *(a[i].group)) {
            for (int p = 0; p < x; ++p) bm.add_edge(i, gid * x + p);
        }
    }

    std::vector<int> matched = bm.match();
    for (int gid = 0; gid < k; ++gid) {
        int cnt = 0;
        for (int i = 0; i < x; ++i) cnt += matched[gid * x + i] != -1 ? 1 : 0;

        printf("%d ", cnt);
        for (int i = 0; i < x; ++i) {
            int applicant_idx = matched[gid * x + i];
            if (applicant_idx != -1) printf("%d ", a[applicant_idx].id + 1);
        }
        printf("\n");
    }

    return 0;
}