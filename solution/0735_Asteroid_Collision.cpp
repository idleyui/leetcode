#include "alg.h"

vector<int> asteroidCollision(vector<int> asteroids) {
    vector<int> v;
    for (int i: asteroids) {
        if (i < 0) {
            while (!v.empty() && v.back() > 0 && v.back() < -i) {
                v.pop_back();
            }
            if (v.empty()) v.push_back(i);
            else if (v.back() == -i)v.pop_back();
            else if (v.back() < 0) v.push_back(i);
        } else if (i > 0) {
            v.push_back(i);
        }
    }
    return v;
}

int main() {
    print_container(asteroidCollision({5, 10, -5}));
    print_container(asteroidCollision({8, -8}));
    print_container(asteroidCollision({10, 2, -5}));
    print_container(asteroidCollision({-2, -1, 1, 2}));
}