#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode *, int> m;
		ListNode * cur = headA;
		while (cur != NULL) {
			m.insert(make_pair(cur, 1));
			cur = cur->next;
		}
		cur = headB;
		while (cur != NULL) {
			if (m.find(cur) != m.end()) {
				return cur;
			}
			cur = cur->next;
		}
		return NULL;
	}
};
ListNode* makeLinkedList(vector<int> a) {
	ListNode * head= new ListNode(a[0]);
	ListNode *cur = head;
	for (int i = 1; i < a.size(); i++) {
		cur->next = new ListNode(a[i]);
		cur = cur->next;
	}
	return head;
}
ListNode* cross(vector<int> b, int v,ListNode *head) {
	ListNode * h2=new ListNode(b[0]);
	if (v != -1) {
		ListNode* cur = head;
		while (cur->val != v) {
			cur = cur->next;
		}
		int i = 1;
		ListNode * cur2 = h2;
		while (b[i] != v) {
			cur2->next = new ListNode(b[i]);
			cur2 = cur2->next;
			i++;
		}
		cur2->next = cur;
	}
	else {
		h2 = makeLinkedList(b);
	}
	return h2;
}
int main() {
	vector<int> a = { 4,1,8,4,5 };
	vector<int> b = { 5,0,1,8,4,5 };
	ListNode* aa=makeLinkedList(a);
	ListNode* bb = cross(b, 8, aa);
	Solution sol = Solution();
	cout<<sol.getIntersectionNode(aa, bb)->val;
	return 0;
}