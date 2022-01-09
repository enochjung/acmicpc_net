#include <cstdio>
#include <algorithm>
#include <vector>

struct point {
	int x, y;
};

int ccw(const point &a, const point &b, const point &c) {
	int value = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
	return value==0? 0 : value/abs(value);
}

int length(const point &a, const point &b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

std::vector<point> get_convex_hull(const std::vector<point> &points) {
	std::vector<point> stack;

	stack.push_back(points[0]);
	stack.push_back(points[1]);
	for (int i=2; i<=(int)points.size(); ++i) {
		point a, b, c;
		bool final_round = i == (int)points.size();
		c = !final_round? points[i] : points[0];
		bool push_c = true;

		while ((int)stack.size() >= 2) {
			b = stack.back();
			stack.pop_back();
			a = stack.back();

			if (ccw(a, b, c) == 0) {
				if (length(a, b) > length(a, c)) {
					stack.push_back(b);
					push_c = false;
				}
				break;
			}
			else if (ccw(a, b, c) < 0) {
				stack.push_back(b);
				break;
			}
		}
		if (push_c && !final_round)
			stack.push_back(c);
	}
	return stack;
}

int main() {
	int p;
	scanf("%d", &p);

	for (int test_case=0; test_case<p; ++test_case) {
		int n;
		scanf("%d", &n);

		std::vector<point> points(n);
		for (int i=0; i<n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = {x, y};
		}

		auto compare_coordinate = [](const point &lhs, const point &rhs) -> bool {
			return lhs.y != rhs.y? lhs.y > rhs.y : lhs.x < rhs.x;
		};
		auto compare_ccw = [&first_point = std::as_const(points[0])](const point &lhs, const point &rhs) -> bool {
			return ccw(first_point, lhs, rhs) < 0;
		};

		std::sort(points.begin(), points.end(), compare_coordinate);
		std::sort(points.begin()+1, points.end(), compare_ccw);

		std::vector<point> convex_hull = get_convex_hull(points);

		printf("%d\n", (int)convex_hull.size());
		for (point p : convex_hull)
			printf("%d %d\n", p.x, p.y);
	}

	return 0;
}