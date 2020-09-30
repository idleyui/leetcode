// https://www.acwing.com/problem/content/788/
#include <iostream>

using namespace std;

const int N = 100010;
int v[N];
int n, k;

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

int topK(int l, int h, int k) {
    if (l >= h)return v[l];

    int m = partition_hoare(l, h);

    int len = m-l+1;
    if(len >= k)    return topK(l, m, k);
    else            return topK(m+1, h, k-len);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << topK(0, n-1, k);
}
