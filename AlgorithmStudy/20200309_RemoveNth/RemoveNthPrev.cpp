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
		ListNode * cur = head, *str = head,*prev=head;
		while (cur != NULL) {
			if (n <= 0) {//n이 1보다 큰경우
				prev = str;
				str = str->next;
			}
			n--;
			cur = cur->next;
		}
		if (str!=prev)
		{
			prev->next = str->next;
			delete str;
			return head;
		}
		else {//둘이 같은경우
			if (str->next!=NULL) {
				head=prev->next;
				delete prev;
				return head;
			}
			delete str;
			return NULL;
		}
	}
};
void main() {
	vector<int> arr = { 1};
	//vector<int> arr = { 1,2,3,4,5 };
	ListNode* head = makelist(arr);
	Solution sol = Solution();
	sol.removeNthFromEnd(head, 1);
}