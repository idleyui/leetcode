#include "alg.h"


int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}


int maxPoints(vector<Point> &points) {
    if (points.size() < 2) return points.size();
    int result = 0;

    for (int i = 0; i < points.size(); i++) {
        map<pair<int, int>, int> lines;
        int localmax = 0, overlap = 0, vertical = 0;

        for (int j = i + 1; j < points.size(); j++) {
            if (points[j].x == points[i].x && points[j].y == points[i].y) {
                overlap++;
                continue;
            } else if (points[j].x == points[i].x) vertical++;
            else {
                int a = points[j].x - points[i].x, b = points[j].y - points[i].y;
                int g = gcd(a, b);
                a /= g;
                b /= g;

                lines[make_pair(a, b)]++;
                localmax = max(lines[make_pair(a, b)], localmax);
            }
            localmax = max(vertical, localmax);
        }
        result = max(result, localmax + overlap + 1);
    }
    return result;
}

void test() {
    cout << gcd(-6, 9);
    cout << (signbit(-6) ^ signbit(3));
    Point p(0, 0);
    Point p1(-1, 1);
    int arrow = 1;
    auto l = line(p, p1, arrow);
    cout << l.first << l.second;
}


void testMax(vector<vector<int>> vv) {
    vector<Point> v;
    for (auto &v1: vv) {
        v.push_back(Point(v1[0], v1[1]));
    }
    cout << maxPoints(v);
}


int main() {
//    testMax({{1, 1}, {2, 2}, {3, 3}});
//    testMax({{0, 0}, {1, 0}});
//    testMax({{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}});
//    testMax({{0, 0}, {1, 1}, {0, 0}});
//    testMax({{0, 0}});
//    testMax({{0, 0}, {0, 0}});
    testMax({{0,  -12},
             {5,  2},
             {2,  5},
             {0,  -5},
             {1,  5},
             {2,  -2},
             {5,  -4},
             {3,  4},
             {-2, 4},
             {-1, 4},
             {0,  -5},
             {0,  -8},
             {-2, -1},
             {0,  -11},
             {0,  -9}});
    Point p1(-2, -1);
    Point p2(-1, 4);
    Point p3(0, -12);
    int x = 1;
}
