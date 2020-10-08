// https://www.acwing.com/problem/content/833/
#include<deque>
#include<vector>
#include<iostream>

using namespace std;

int main() {
    int n, k, num, left;
    cin >> n >> k;
    deque<int> up_q, down_q, q;
    vector<int> min_v, max_v;
    for(int i = 0; i < n; i++) {
        cin >> num;
        while(!up_q.empty() && up_q.back() > num) up_q.pop_back();
        up_q.push_back(num);
        while(!down_q.empty() && down_q.back() < num) down_q.pop_back();
        down_q.push_back(num);

        q.push_back(num);
        if(i >= k-1){
            min_v.push_back(up_q.front());
            max_v.push_back(down_q.front());
            left = q.front();
            q.pop_front();
            if (left == up_q.front()) up_q.pop_front();
            if (left == down_q.front()) down_q.pop_front();
        }
    }

    for(int i: min_v) cout << i << ' ';
    cout << endl;
    for(int i: max_v) cout << i << ' ';
}
