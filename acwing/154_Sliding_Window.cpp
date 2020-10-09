// https://www.acwing.com/problem/content/156/
#include<deque>
#include<vector>
#include<iostream>

using namespace std;

vector<int> get_min_by_dataflow() {
    int n, k, num;
    cin >> n >> k;
    deque<int> up_q, q;
    vector<int> min_v;
    for(int i = 0; i < n; i++) {
        cin >> num;
        while(!up_q.empty() && up_q.back() > num) up_q.pop_back();
        up_q.push_back(num);

        q.push_back(num);
        if(i >= k-1){
            min_v.push_back(up_q.front());
            int left = q.front();
            q.pop_front();
            if (left == up_q.front()) up_q.pop_front();
        }
    }
    return min_v;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n, 0);
    for(int i = 0; i < n; i++) cin >> A[i];

    deque<int> q;
    vector<int> min_v, max_v;

    // save the index to check front item out
    for(int i = 0; i < n; i++) {
        while(!q.empty() && A[q.back()] >= A[i]) q.pop_back();
        q.push_back(i);
        if(q.front() <= i - k) q.pop_front();
        if(i >= k-1)min_v.push_back(A[q.front()]);
    }

    q.clear();
    for(int i = 0; i < n; i++) {
        while(!q.empty() && A[q.back()] <= A[i]) q.pop_back();
        q.push_back(i);
        if(q.front() <= i - k) q.pop_front();
        if(i>=k-1)max_v.push_back(A[q.front()]);
    }

    for(int i: min_v) cout << i << ' ';
    cout << endl;
    for(int i: max_v) cout << i << ' ';
}
