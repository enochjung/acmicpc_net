#include <cstdio>
#include <optional>
#define N 100001

struct sample {
	int rep_idx;
	int my_weight_minus_rep;
};

sample s[N];

int get_rep(int a) {
	if (a == s[a].rep_idx)
		return a;
	int rep_rep = get_rep(s[a].rep_idx);
	s[a].my_weight_minus_rep += s[s[a].rep_idx].my_weight_minus_rep;
	return s[a].rep_idx = rep_rep;
}

void set_b_minus_a(int a, int b, int b_minus_a) {
	int a_rep = get_rep(a);
	int b_rep = get_rep(b);
	int a_minus_a_rep = s[a].my_weight_minus_rep;
	int b_minus_b_rep = s[b].my_weight_minus_rep;

	if (a_rep < b_rep) {
		s[b_rep].rep_idx = a_rep;
		s[b_rep].my_weight_minus_rep = b_minus_a + a_minus_a_rep - b_minus_b_rep;
	}
	else if (a_rep > b_rep) {
		s[a_rep].rep_idx = b_rep;
		s[a_rep].my_weight_minus_rep = -b_minus_a - a_minus_a_rep + b_minus_b_rep;
	}
}

std::optional<int> get_b_minus_a(int a, int b) {
	int a_rep = get_rep(a);
	int b_rep = get_rep(b);
	int a_minus_rep = s[a].my_weight_minus_rep;
	int b_minus_rep = s[b].my_weight_minus_rep;

	if (a_rep != b_rep)
		return std::nullopt;
	return b_minus_rep - a_minus_rep;
}

int main() {
	while (true) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0)
			break;

		for (int i=1; i<=n; ++i) {
			s[i].rep_idx = i;
			s[i].my_weight_minus_rep = 0;
		}

		while (m--) {
			char type;
			int a, b, w;
			scanf(" %c", &type);
			if (type == '!') {
				scanf("%d %d %d", &a, &b, &w);
				set_b_minus_a(a, b, w);
			}
			else if (type == '?') {
				scanf("%d %d", &a, &b);
				std::optional<int> result = get_b_minus_a(a, b);
				if (result.has_value())
					printf("%d\n", result.value());
				else
					printf("UNKNOWN\n");
			}
		}
	}
	return 0;
}