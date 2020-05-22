#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
  ListNode* makelist(vector<int> arr) {
	  ListNode * head = new ListNode(arr[0]);
	  ListNode *cur = head;
	  for (int i = 1; i < arr.size(); i++) {
		  cur->next = new ListNode(arr[i]);
		  cur = cur->next;
	  }
	  return head;
  }

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode *> node;
		ListNode * cur = head;
		while (cur != NULL) {
			node.push_back(cur);
			cur = cur->next;
		}
		if (node.size() < n + 1) {
			if (node.size() == n) return head->next;
			return NULL;
		}
		ListNode * prev = node[node.size() - n - 1];
		cur = node[node.size() - n];
		prev->next = cur->next;
		return node[0];
	}
};
void main() {
	//vector<int> arr = { 1};
	vector<int> arr = { 1,2,3,4,5 };
	ListNode* head = makelist(arr);
	Solution sol = Solution();
	sol.removeNthFromEnd(head, 5);
}