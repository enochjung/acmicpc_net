#include <cstdio>
#include <cmath>
#define N 500000

int idx2num[N+1], num2idx[N+1], cnt[N+1];

void swap_position(int idx1, int idx2) {
	int dist = abs(idx1-idx2);
	int num1 = idx2num[idx1];
	int num2 = idx2num[idx2];

	cnt[num1] += dist;
	cnt[num2] += dist;

	num2idx[num1] = idx2;
	num2idx[num2] = idx1;

	idx2num[idx1] = num2;
	idx2num[idx2] = num1;
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", idx2num+i);
		num2idx[idx2num[i]] = i;
	}

	for (int i=1; i<=n; ++i)
		swap_position(i, num2idx[i]);
	
	for (int i=1; i<=n; ++i)
		printf("%d ", cnt[i]);
	printf("\n");

    return 0;
}