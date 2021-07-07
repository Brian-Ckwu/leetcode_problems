#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) {
      return (l1 ? l1 : l2);
    }
    
    ListNode* ref = (l1->val <= l2->val) ? l1 : l2;
    ListNode* comp = (ref == l1) ? l2 : l1; // Be careful
    ListNode* temp = nullptr;
    ListNode* head = ref;
    
    while (ref->next && comp) {
      if (comp->val <= ref->next->val) {
        // handle comp list
        temp = comp;
        comp = comp->next;
        // handle ref list
        temp->next = ref->next;
        ref->next = temp; // Be careful, ref->next = temp;
        ref = ref->next;
      } else {
        ref = ref->next;
      }
    }
    
    if (comp) {
      ref->next = comp;
    }
    
    return head;
  }
};

void printList(ListNode* node) {
  while (node) {
    cout << node->val << " ";
    node = node->next;
  }
}

int main() {
  ListNode* node3 = new ListNode(4);
  ListNode* node2 = new ListNode(2, node3);
  ListNode* node1 = new ListNode(1, node2);
  
  ListNode* node6 = new ListNode(4);
  ListNode* node5 = new ListNode(3, node6);
  ListNode* node4 = new ListNode(1, node5);

  ListNode* l1 = node1;
  ListNode* l2 = node4;

  Solution sol;

  printList(sol.mergeTwoLists(l1, l2));

  return 0;
}