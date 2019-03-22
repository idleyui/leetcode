#include "alg.h"

class MyLinkedList {
public:
    MyLinkedList() {}

    int get(int index) {
        if (index < 0 || index >= size)return -1;
        ListNode *p = head;
        for (int i = 0; i < index; i++)p = p->next;
        return p->val;
    }

    void addAtHead(int val) {
        ListNode *p = new ListNode(val);
        p->next = head;
        head = p;
        size++;
    }

    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
            return;
        }
        ListNode *p = head;
        while (p->next)p = p->next;
        p->next = new ListNode(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode **p = &head;
        for (int i = 0; i < index; ++i) {
            p = &(*p)->next;
        }
        ListNode *tmp = *p;
        *p = new ListNode(val);
        (*p)->next = tmp;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode **p = &head;
        for (int i = 0; i < index; ++i) {
            p = &(*p)->next;
        }
        *p = (*p)->next;
        size--;
    }

private:

    struct ListNode {
        int val;
        ListNode *next = nullptr;

        ListNode(int x) : val(x), next(NULL) {}
    };

    int size = 0;
    ListNode *head = nullptr;
};


int main() {
    MyLinkedList lst{};
//    cout << lst.get(-1);
//    cout << lst.get(0);
//    cout << lst.get(0);
    lst.addAtHead(1);
    lst.addAtTail(3);
    lst.addAtIndex(1, 2);
    cout << lst.get(1);
    lst.deleteAtIndex(1);
    cout << lst.get(1);
}
