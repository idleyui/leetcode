#include "alg.h"

int partition(vector<int> &v, int l, int h) {
    int val = v[l];
    int i = l + 1, j = h;
    while (i <= j) {
        while (v[i] <= val)i++;
        while (v[j] <= val)j--;
        if (i < j)swap(v[i++], v[j--]);
        else i++;
    }
    swap(v[j], val);
    return j;
}

void qsort(vector<int> &v, int l, int h) {
    if (l >= h)return;
    int m = partition(v, l, h);
    qsort(v, l, m - 1);
    qsort(v, m + 1, h);
}


int main() {

}