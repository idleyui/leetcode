// https://www.acwing.com/problem/content/789/
#include <iostream>

using namespace std;

const int N = 100010;
int A[N], B[N];
int n;

void merge(int l, int h) {
    int mid = l + (h-l)/2;
    int bi = l;
    for(int i = l, j = mid+1; i <= mid || j <= h;) {
        if (i > mid) B[bi++] = A[j++];
        else if (j > h) B[bi++] = A[i++];
        else if (A[i] < A[j])   B[bi++] = A[i++];
        else B[bi++] = A[j++];
    }

    for(int i = l; i <= h; i++) A[i] = B[i];
}

void merge_sort(int l, int h){
    if(l >= h)  return;
    int mid = l + (h-l)/2;
    merge_sort(l, mid);
    merge_sort(mid+1, h);
    merge(l, h);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    merge_sort(0, n-1);

    for(int i = 0; i < n; i++) cout << A[i] << ' ';
}
