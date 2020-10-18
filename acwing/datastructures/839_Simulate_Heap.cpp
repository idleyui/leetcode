// https://www.acwing.com/problem/content/841/
#include<iostream>

using namespace std;

const int N = 100010;
int A[N], B[N], C[N], n=0, idx=0, m;

void swap_heap(int i, int j) {
    swap(A[i], A[j]);
    swap(C[B[i]], C[B[j]]);
    swap(B[i], B[j]);
}

void heapify(int i) {
    for (i = i*2+1; i < n; i=i*2+1){
        if (i + 1 < n && A[i + 1] < A[i]) i++;
        if (A[(i - 1) / 2] < A[i]) break;
        swap_heap((i-1)/2, i);
    }
}

void up(int i) {
    for(; A[i] > A[(i-1)/2]; i = (i-1)/2) heapify((i-1)/2);
}

int pop() {
    int ans = A[0];
    swap_heap(0, n-1);
    n--;
    heapify(0);
    return ans;
}

int main() {
    cin >> m;
    string op;
    int k, x;
    while(m--) {
        cin >> op;
        if (op == "I") {
            cin >> x;
            A[n] = x;
            B[n]= idx;
            C[idx++] = n++;
            up(n-1);
        } else if (op == "PM") {
            cout << A[0] << endl;
        } else if (op == "D") {
            cin >> k;
            int i = C[k];
            swap_heap(C[k], n-1);
            n--;
            up(i);
        } else if (op == "C") {
            cin >> k >> x;
            int i = C[k];
            A[i] = x;
            up(i);
        } else if (op == "DM") {
            cout << pop() << endl;
        }
    }

}
