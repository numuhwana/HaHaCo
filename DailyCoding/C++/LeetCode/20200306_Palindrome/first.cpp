#include <iostream>
#include <vector>
using namespace std;

//definition for singly-linked list.
  struct ListNode {
      int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> arr;
		ListNode * cur = head;
		int cnt = 0,cnt2=0;
		while (cur != NULL) {
			cnt++;
			arr.push_back(cur->val);
			cur = cur->next;
		}
		cur = head;
		while (cur != NULL) {
			cnt2++;
			if (cnt2 == floor(cnt / 2) + 1) return true;
			if (cur->val != arr.back()) return false;
			arr.pop_back();
			cur = cur->next;
		}
	}
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
void main() {
	//vector<int> arr = { 1,2,1,2 };
		vector<int> arr = { 1,2,2,1 };
	ListNode* head=makelist(arr);
	Solution sol = Solution();
	cout<<sol.isPalindrome(head)<<endl;
}