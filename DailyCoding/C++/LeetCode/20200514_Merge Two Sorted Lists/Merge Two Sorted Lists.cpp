#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * nw;
        ListNode * head=NULL;
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else {
            if (l1->val < l2->val) {
                nw = l1;
                l1 = l1->next;
            }
            else {
                nw = l2;
                l2 = l2->next;
            }
        }
        head = nw;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                nw->next = l1;
                l1 = l1->next;
            }
            else {
                nw->next = l2;
                l2 = l2->next;
            }
            nw = nw->next;
        }
        while (l1 != NULL) {
            nw->next = l1;
            l1 = l1->next;
            nw = nw->next;
        }
        while (l2 != NULL) {
            nw->next = l2;
            l2 = l2->next;
            nw = nw->next;
        }
        return head;
    }
};
void print(ListNode * h) {
    while (h != NULL) {
        cout << h->val<<"->";
        h = h->next;
    }cout << endl;
}
ListNode* makeNode(vector<int> v) {
    ListNode * head,*cur;
    head = new ListNode(v[0]);
    cur = head;
    for (int i = 1; i < v.size(); i++) {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    return head;
}
int main() {
    vector<int> v1 = {1,2,4};
    vector<int> v2 = {1,3,4};
    ListNode * l1 = makeNode(v1);
    ListNode * l2 = makeNode(v2);
    Solution s = Solution();
    ListNode* h=s.mergeTwoLists(l1, l2);
    print(h);
    return 0;
}