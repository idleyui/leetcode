#include "alg.h"

vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    vector<pair<int, int>> cnt(10001, {0, 0});
    for (int i = 0; i < 10001; i++) cnt[i].first = i;
    for (int i: barcodes) cnt[i].second++;
    sort(cnt.begin(), cnt.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    });

    int j = 0, i = 0;
    while (i < barcodes.size()) {
        if (cnt[j].second == 0) {
            j++;
            continue;
        }
        barcodes[i] = cnt[j].first;
        cnt[j].second--;
        i += 2;
        if (i >= barcodes.size() && i % 2 == 0) i = 1;
    }
    return barcodes;
}


int main() {

}