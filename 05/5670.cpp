#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

struct word {
	char str[81];

	word() {
		str[0] = 0;
	}
	void scan() {
		scanf("%s", str);
	}
	bool operator<(const word &rhs) {
		return strcmp(str, rhs.str) <= 0;
	}
};

int count(std::vector<word> &dic, int start, int end, int nth_char, bool must_type) {
	int result = 0;
	int kind = 0;

	if (start >= end)
		return 0;
	if (dic[start].str[nth_char] == 0)
		return count(dic, start+1, end, nth_char, true);
	
	for (int i=start, j=start; i<end; ++i)
		if (i+1==end || dic[i].str[nth_char] != dic[i+1].str[nth_char]) {
			result += count(dic, j, i+1, nth_char+1, false);
			j = i+1;
			++kind;
		}

	return kind>1 || must_type? result + end-start : result;
}

int main() {
	while (true) {
		int n;
		if (scanf("%d", &n) != 1)
			break;
		
		std::vector<word> dic(n);
		for (int i=0; i<n; ++i)
			dic[i].scan();

		std::sort(dic.begin(), dic.end());
		printf("%.2lf\n", (double)count(dic, 0, n, 0, true) / n);
	}

	return 0;
}