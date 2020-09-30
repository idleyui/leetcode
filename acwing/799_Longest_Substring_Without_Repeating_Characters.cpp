// https://www.acwing.com/problem/content/801/
#include <vector>
#include <iostream>

using namespace std;

int N = 100010;

int length(vector<int> &a) {
    int l = 0, r = 0, MAX = 0;
    vector<int> lastpos(N, -1);
    while (r < a.size()) {
        while (r < a.size() && lastpos[a[r]] < l) {
            lastpos[a[r]] = r;
            r++;
        }
        MAX = max(MAX, r - l);
        l = lastpos[a[r]] + 1;
    }
    return MAX;
}

int len(vector<int> &a, int n) {
    vector<int> cnt(N, 0);
    int MAX = 0;
    for (int r = 0, l = 0; r < n; r++) {
        cnt[a[r]]++;
        while (cnt[a[r]] > 1) {
            cnt[a[l]]--;
            l++;
        }
        MAX = max(MAX, r - l + 1);
    }
    return MAX;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(N, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << length(a);
}