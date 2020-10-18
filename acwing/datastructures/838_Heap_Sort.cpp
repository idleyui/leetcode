// https://www.acwing.com/problem/content/840/
#include<iostream>

using namespace std;

const int N = 100010;
int A[N], n, m;

void heapify(int i) {
    for (i = i*2+1; i < n; i=i*2+1){
        if (i + 1 < n && A[i + 1] < A[i]) i++;
        if (A[(i - 1) / 2] < A[i]) break;
        swap(A[(i - 1) / 2], A[i]);
    }
}

int pop() {
    int ans = A[0];
    swap(A[0], A[n - 1]);
    n--;
    heapify(0);
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> A[i];

    for (int i = n/2-1; i >= 0; i--) heapify(i);

    while (m--) cout << pop() << ' ';
}
