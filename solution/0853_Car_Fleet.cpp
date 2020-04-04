#include "alg.h"

int carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<pair<int, int>> pos_spd;
    for (int i = 0; i < speed.size(); i++) {
        pos_spd.push_back({position[i], speed[i]});
    }

    sort(pos_spd.begin(), pos_spd.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    });

    double last_time_arrive = -1;
    int cnt = 0;
    for (auto &p: pos_spd) {
        double time_arrive = (double) (target - p.first) / (double) p.second;
        if (time_arrive > last_time_arrive) {
            last_time_arrive = time_arrive;
            cnt++;
        }
    }
    return cnt;
}

int main() {

}