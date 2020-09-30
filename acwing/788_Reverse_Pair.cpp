// https://www.acwing.com/problem/content/790/
#include <iostream>

using namespace std;

const int N = 100010;
int A[N], B[N];
int n;
long long cnt;

// fix j, count (i...mid,j)(i > j) as reverse pair
void merge(int l, int h) {
    int mid = l + (h-l)/2;
    int bi = l, i = l, j = mid+1;
    while(i <= mid && j <= h) {
        if (A[i] <= A[j]){
            B[bi++] = A[i++];
        }  else {
            cnt += mid-i+1;
            B[bi++] = A[j++];
        }
    }

    while(i<=mid){   B[bi++] = A[i++];   }
    while(j<=h)   B[bi++] = A[j++];
    for(i = l; i <= h; i++) A[i] = B[i];
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
    cout << cnt;
}
