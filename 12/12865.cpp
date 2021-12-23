#include <cstdio>
#include <algorithm>
#include <queue>
#define N 100
#define INF 999999

using namespace std;

struct st
{
	int weight, value;
	bool operator<(const st &i) const
	{
		return weight < i.weight;
	}
};

int n, k;
st a[N];
queue<st> q[2];

int get_front_weight(queue<st> *p)
{
	return p->empty()? INF : p->front().weight;
}

void update(int weight, int value, queue<st> *q_from, queue<st> *q_to, queue<st> *p)
{
	if (q_from->front().weight == get_front_weight(p))
	{
		q_to->push({q_from->front().weight, max(q_from->front().value, p->front().value)});
		p->pop();
	}
	else
		q_to->push(q_from->front());
	
	if (q_from->front().weight + weight <= k)
		p->push({q_from->front().weight + weight, q_from->front().value + value});

	q_from->pop();

	while (!p->empty() && get_front_weight(p) < get_front_weight(q_from))
	{
		q_to->push({p->front().weight, p->front().value});
		p->pop();
	}
}

int main()
{
	queue<st> p;
	
	scanf("%d %d", &n, &k);
	q[0].push({0, 0});

	for (int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].weight, &a[i].value);
	
	sort(a, a+n);

	for (int i = 0; i < n; ++i)
		while (!q[i&1].empty())
			update(a[i].weight, a[i].value, &q[i&1], &q[1-(i&1)], &p);
	
	int result = 0;
	while (!q[n&1].empty())
	{
		result = max(result, q[n&1].front().value);
		q[n&1].pop();
	}

	printf("%d", result);
	return 0;
}