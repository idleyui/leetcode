#include "alg.h"

void reversePrint(vector<int> &arr, ListNode *head) {
    if (!head) return;
    reversePrint(arr, head->next);
    arr.push_back(head->val);
}

vector<int> reversePrint(ListNode *head) {
    vector<int> arr;
    reversePrint(arr, head);
    return arr;
}

vector<int> reversePrint(ListNode *head) {
    vector<int> stk;
    while (head) {
        stk.push_back(head->val);
        head = head->next;
    }
    reverse(stk.begin(), stk.end());
    return stk;
}

int main() {

}