#include "algorithm"
#include "iostream"
#include "vector"
#include "random"

using namespace std;

void print(vector<int> &v) {
    for (int i: v) cout << i << ", ";
    cout << endl;
}


// sort odd first
bool cmp(const int &i1, const int &i2) {
    return i1 % 2 < i2 % 2;
}

void custom_sort(vector<int> &v) {
    // custom sort
    make_heap(v.begin(), v.end(), cmp);
    print(v);

    v.push_back(100);
    push_heap(v.begin(), v.end(), cmp);
    print(v);

    pop_heap(v.begin(), v.end(), cmp);
    print(v);
    v.pop_back();

//    sort_heap(v.begin(), v.end());
//    printf("wrong ans");
//    print(v);
    sort_heap(v.begin(), v.end(), cmp);
    print(v);
}

void basic_demo(vector<int> &v) {
    // make min heap
    // make_heap(v.begin(), v.end(), greater<int>());

    // make max heap
    make_heap(v.begin(), v.end());
    print(v);


    // adjust heap from last item
    v.push_back(10);
    push_heap(v.begin(), v.end());
    print(v);


    // swap first to last, adjust first n-1
    pop_heap(v.begin(), v.end());
    print(v);
    // need pop back
    v.pop_back();
    print(v);

    // sort heap
    sort_heap(v.begin(), v.end());
    print(v);
}


//https://elloop.github.io/c++/2016-11-29/learning-using-stl-72-make-heap
int main() {
    vector<int> v(10, 0);
    for (int i = 0; i < 10; i++) { v[i] = i; }
    random_shuffle(v.begin(), v.end());
    print(v);

    custom_sort(v);
}