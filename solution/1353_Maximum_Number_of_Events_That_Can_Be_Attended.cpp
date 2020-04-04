#include "alg.h"


int maxEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int today = events[0][0], n = events.size(), cnt = 0, i = 0;
    while (i < n || !pq.empty()) {
        if (pq.empty()) {
            today = events[i][0];
        }
        for (; i < n && events[i][0] <= today; i++) {
            pq.push(events[i][1]);
        }
        if (!pq.empty()) {
            auto e = pq.top();
            pq.pop();
            if (e >= today) {
                cnt++;
                today++;
            }

        }
    }
    return cnt;
}

int main() {

}