#include <algorithm>
#include <stack>
#include <vector>

class scc {
   public:
    static std::vector<std::vector<int>> get(
        int n, const std::vector<std::vector<int>> &edge) {
        std::vector<std::vector<int>> scc_vec;
        std::vector<int> dfsn;
        std::vector<bool> finish;
        std::stack<int> stack;
        int count = 0;

        dfsn.resize(n);
        finish.resize(n);

        for (int i = 0; i < n; ++i)
            if (dfsn[i] == 0) dfs(edge, i, scc_vec, dfsn, finish, stack, count);

        return scc_vec;
    };

   private:
    static int dfs(const std::vector<std::vector<int>> &edge, int x,
                   std::vector<std::vector<int>> &scc_vec,
                   std::vector<int> &dfsn, std::vector<bool> &finish,
                   std::stack<int> &stack, int &count) {
        dfsn[x] = ++count;
        stack.push(x);

        int top = dfsn[x];
        for (int to : edge[x]) {
            if (dfsn[to] == 0)
                top = std::min(
                    top, dfs(edge, to, scc_vec, dfsn, finish, stack, count));
            else if (!finish[to])
                top = std::min(top, dfsn[to]);
        }

        if (top == dfsn[x]) {
            std::vector<int> now_scc;
            int v = -1;

            while (v != x) {
                v = stack.top();
                stack.pop();
                finish[v] = true;
                now_scc.push_back(v);
            }

            scc_vec.push_back(now_scc);
        }

        return top;
    }
};