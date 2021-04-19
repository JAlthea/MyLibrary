#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

double getPolygonArea(vector<pair<long long, long long>> & points) {
    long long area = 0;
    for (int i = 0; i < n; ++i) {
        area += (points[i].first + points[(i + 1) % n].first) * (points[i].second - points[(i + 1) % n].second);
    }
    return (double)abs(area) / 2;
}

