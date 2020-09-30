// https://www.acwing.com/problem/content/787/
#include <vector>
#include <iostream>

using namespace std;

const int N = 100010;
int n;
vector<int> v(N, 0);

// hoare partition: left / right pointer
int partition_hoare(int l, int h) {
    int val = v[l + h >> 1];
    l = l - 1, h = h + 1;
    while (l < h) {
        do l++; while (v[l] < val);
        do h--; while (v[h] > val);
        if (l < h)swap(v[l], v[h]);
    }
    return h;
}

void qsort_hoare(int l, int h) {
    if (l >= h)return;

    int m = partition_hoare(l, h);
    qsort_hoare(l, m);
    qsort_hoare(m + 1, h);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    qsort_hoare(0, n - 1);
    for (int i = 0; i < n; i++) cout << v[i] << ' ';
}
