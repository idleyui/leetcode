// https://www.acwing.com/problem/content/793/
// !note
// remember string to vector a[i]-'0'
#include<vector>
#include<iostream>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int carry = 0;
    for (int i = 0, j = 0; i < A.size() || j < B.size() || carry; i++, j++) {
        if (i < A.size()) carry += A[i];
        if (j < B.size()) carry += B[j];
        ans.push_back(carry % 10);
        carry = carry / 10;
    }
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto ans = add(A, B);
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}

//use string
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int N = 100010;
//string a,b;
//
//string add() {
//    string ans;
//    int carry = 0, i = 0, j = 0;
//    while(i < a.size() || j < b.size() || carry) {
//        if (i < a.size()) carry += a[i++]-'0';
//        if (j < b.size()) carry += b[j++]-'0';
//        ans.push_back((char)('0' + carry % 10));
//        carry /= 10;
//    }
//    reverse(ans.begin(), ans.end());
//    return ans;
//}
//
//int main() {
//    cin >> a >> b;
//    reverse(a.begin(), a.end());
//    reverse(b.begin(), b.end());
//    cout << add();
//}
