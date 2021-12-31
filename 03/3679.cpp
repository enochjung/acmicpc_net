#include <cstdio>
#include <algorithm>
#include <vector>

struct point {
	int x, y;
	int idx;
};

int ccw(const point &a, const point &b, const point &c) {
	int value = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
	return value==0? 0 : value/abs(value);
}

std::vector<point> get_convex_hull(const std::vector<point> &points) {
	std::vector<point> stack;
	stack.push_back(points[0]);
	stack.push_back(points[1]);
	for (int i=2; i<(int)points.size(); ++i) {
		for (int size=(int)stack.size(); size>=2 && ccw(stack[size-2], stack[size-1], points[i])<0; --size)
			stack.pop_back();
		stack.push_back(points[i]);
	}
	return stack;
}

std::vector<point> get_bottom_convex_hull(const std::vector<point> &convex_hull) {
	std::vector<point> bottom;
	bottom.push_back(convex_hull[0]);
	for (int i=1; i<(int)convex_hull.size(); ++i) {
		if (convex_hull[i].x < convex_hull[i-1].x)
			break;
		bottom.push_back(convex_hull[i]);
	}
	return bottom;
}

int main() {
	int c;
	scanf("%d", &c);

	for (int test_case=0; test_case<c; ++test_case) {
		int n;
		scanf("%d", &n);

		std::vector<point> points(n);
		for (int i=0; i<n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = {x, y, i};
		}

		auto compare_coordinate = [](const point &lhs, const point &rhs) -> bool {
			return lhs.x != rhs.x? lhs.x < rhs.x : lhs.y < rhs.y;
		};
		auto compare_ccw = [&leftmost_point = std::as_const(points[0])](const point &lhs, const point &rhs) -> bool {
			int value = ccw(leftmost_point, lhs, rhs);
			return value!=0? value>0 : lhs.x<rhs.x;
		};

		std::sort(points.begin(), points.end(), compare_coordinate);
		std::sort(points.begin()+1, points.end(), compare_ccw);

		std::vector<point> bottom = get_bottom_convex_hull(get_convex_hull(points));
		std::sort(points.begin(), points.end(), compare_coordinate);

		for (point p : points)
			if (!std::binary_search(bottom.begin(), bottom.end(), p, compare_coordinate))
				printf("%d ", p.idx);
		for (auto rit=bottom.rbegin(); rit!=bottom.rend(); ++rit)
			printf("%d ", rit->idx);
		printf("\n");
	}

	return 0;
}