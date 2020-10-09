// https://www.acwing.com/problem/content/242/
#include<iostream>

using namespace std;

const int N = 100010;

int parent[N], cnt[N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
}
