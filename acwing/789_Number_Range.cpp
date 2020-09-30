// https://www.acwing.com/problem/content/791/
#include <iostream>

using namespace std;

const int N = 100010;
int A[N];
int n, q, k;

int find(int val) {
    int l = 0, h = n;
    while(l < h) {
        int mid = l + (h-l)/2;
        if (A[mid] < val) l=mid+1;
        else    h=mid;
    }
    return h;
}

void range(int &left, int &right) {
    left = find(k);
    if(left == n || A[left] != k) {
        left = right = -1;
        return;
    }
    right = find(k+1);
    right = right-1;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> A[i];

    int left, right;
    while (q--) {
        cin >> k;
        range(left, right);
        cout << left << ' ' << right << endl;
    }

}
