#include <cstdio>
#include <functional>
#include <optional>
#include <vector>

#define MAX_UNIFORM_NUM 1000000

struct uniform {
    int p, q;
};

std::optional<std::vector<int>> choose_uniform_number(
    const std::vector<uniform> &a) {
    int n = a.size();

    struct edge {
        int person_idx, another_uniform_num;
    };

    std::vector<int> chosen_num(n, -1);
    std::vector<int> ancestor(MAX_UNIFORM_NUM);
    std::vector<bool> avail(MAX_UNIFORM_NUM, true);
    std::vector<std::vector<edge>> choice(MAX_UNIFORM_NUM, std::vector<edge>());

    std::function<bool(int)> is_avail = [&avail](int uniform_num) {
        return avail[uniform_num];
    };

    std::function<bool(int)> doesnt_choose = [&chosen_num](int person_idx) {
        return chosen_num[person_idx] == -1;
    };

    std::function<void(int, int)> choose =
        [&choose, &avail, &chosen_num, &choice, &doesnt_choose](
            int person_idx, int uniform_num) {
            avail[uniform_num] = false;
            chosen_num[person_idx] = uniform_num;

            std::vector<edge> &others_choice = choice[uniform_num];
            while (!others_choice.empty()) {
                edge &e = others_choice.back();
                int other_idx = e.person_idx;
                int other_uniform_num = e.another_uniform_num;
                others_choice.pop_back();

                if (doesnt_choose(other_idx))
                    choose(other_idx, other_uniform_num);
            }
        };

    std::function<int(int)> get_ancestor = [&ancestor,
                                            &get_ancestor](int uniform_num) {
        if (uniform_num != ancestor[uniform_num])
            ancestor[uniform_num] = get_ancestor(ancestor[uniform_num]);
        return ancestor[uniform_num];
    };

    std::function<bool(int, int)> does_connection_create_cycle =
        [&get_ancestor](int uniform_a, int uniform_b) {
            return get_ancestor(uniform_a) == get_ancestor(uniform_b);
        };

    std::function<void(int, int, int)> connect =
        [&choice, &ancestor, &get_ancestor](int person_idx, int uniform_a,
                                            int uniform_b) {
            choice[uniform_a].push_back({person_idx, uniform_b});
            choice[uniform_b].push_back({person_idx, uniform_a});
            int ancestor_a = get_ancestor(uniform_a);
            int ancestor_b = get_ancestor(uniform_b);
            ancestor[ancestor_a] = ancestor_b;
        };

    for (int i = 0; i < MAX_UNIFORM_NUM; ++i) ancestor[i] = i;

    for (int i = 0; i < n; ++i) {
        int p = a[i].p;
        int q = a[i].q;
        bool p_avail = is_avail(p);
        bool q_avail = is_avail(q);

        if (!p_avail && !q_avail)
            return std::nullopt;
        else if (!p_avail)
            choose(i, q);
        else if (!q_avail)
            choose(i, p);
        else {
            if (does_connection_create_cycle(p, q))
                choose(i, p);
            else
                connect(i, p, q);
        }
    }

    for (int i = 0; i < n; ++i)
        if (doesnt_choose(i)) choose(i, a[i].p);
    return chosen_num;
}

int main() {
    int n;
    std::vector<uniform> a;

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        int p, q;
        scanf("%d %d", &p, &q);
        a[i] = {p - 1, q - 1};
    }

    std::optional<std::vector<int>> res = choose_uniform_number(a);

    if (res.has_value())
        for (int val : res.value()) printf("%d\n", val + 1);
    else
        printf("-1\n");

    return 0;
}