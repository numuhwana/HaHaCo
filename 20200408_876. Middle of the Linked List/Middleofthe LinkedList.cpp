#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
      int val;
    ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		int i = 0;
		ListNode * cur = head;
		while (cur != NULL) {
			i++;
			cur = cur->next;
		}
		i = floor(i / 2);
		cur = head;
		while (i > 0) {
			i--;
			cur = cur->next;
		}
		return cur;
	}
};
ListNode* makeLinkedList(vector<int> a) {
	ListNode * head=new ListNode(a[0]);
	ListNode * cur = head;
	for (int i = 1; i < a.size(); i++) {
		cur->next = new ListNode(a[i]);
		cur = cur->next;
	}
	return head;
}
int main() {
	vector<int> arr = { 1,2,3,4,5,6 };
	ListNode * h = makeLinkedList(arr);
	Solution sol = Solution();
	cout<<sol.middleNode(h)->val;
}