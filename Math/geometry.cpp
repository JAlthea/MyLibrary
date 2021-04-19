#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;


template <class T, class Enable = void>
struct Line {};

template <class T>
struct Line <T, typename std::enable_if<std::is_arithmetic<T>::value>::type> {
	pair<T, T> a;
	pair<T, T> b;

	Line() {
		a.first = 0;
		a.second = 0;
		b.first = 0;
		b.second = 0;
	}

	Line(T x1, T y1, T x2, T y2) {
		a.first = x1;
		a.second = y1;
		b.first = x2;
		b.second = y2;
	}

	Line(pair<T, T> a, pair<T, T> b) {
		this.a.first = a.first;
		this.a.second = a.second;
		this.b.first = b.first;
		this.b.second = b.second;
	}

	template <typename T>
	Line(Line<T> l) {
		a.first = l.a.first;
		a.second = l.a.second;
		b.first = l.b.first;
		b.second = l.b.second;
	}
};

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, int> CCW(pair<T, T> & p1, pair<T, T> & p2, pair<T, T> & p3) {
	T ret = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret > 0) return 1;
	if (ret < 0) return -1;
	return 0;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> isLineContainPoint(Line<T> & l, pair<T, T> & p) {
	T x1 = l.a.first;
	T y1 = l.a.second;
	T x2 = l.b.first;
	T y2 = l.b.second;
	T x3 = p.first;
	T y3 = p.second;

	if (x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2)
		return true;
	if (x1 <= x3 && x3 <= x2 && y1 >= y3 && y3 >= y2)
		return true;
	if (x1 >= x3 && x3 >= x2 && y1 <= y3 && y3 <= y2)
		return true;
	if (x1 >= x3 && x3 >= x2 && y1 >= y3 && y3 >= y2)
		return true;

	return false;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, double> getPolygonArea(vector<pair<T, T>> & points) {
	long long area = 0;
	for (int i = 0; i < points.size(); ++i) {
		area += (points[i].first + points[(i + 1) % points.size()].first) * (points[i].second - points[(i + 1) % points.size()].second);
	}
	return (double)abs(area) / 2;
}

