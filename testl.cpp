#include "alg.h"
ListNode *removeN(ListNode *head, int n){
  if(head == NULL)return NULL;
  ListNode h(0);
  h.next = head;
  ListNode *p = h.next, *remove = &h;
  int i = 0;
  for(; i < n && p;i++)p = p->next;
  // n 大于链表长度
  if(i != n-1)return NULL;

  while(p){
    p = p->next;
    remove=remove->next;
  }

  remove->next = remove->next->next;
  return h.next;
}
int main() {
    ListNode *node = mklst({1,2,3});
  printList(removeN(node, 1));
//    cout << "ok";
}