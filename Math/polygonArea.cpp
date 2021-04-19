#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

double getPolygonArea(vector<pair<long long, long long>> & points) {
    long long area = 0;
    for (int i = 0; i < n; ++i) {
        area += (arr[i].first + arr[(i + 1) % n].first) * (arr[i].second - arr[(i + 1) % n].second);
    }
    return (double)abs(area) / 2;
}

