#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& p) {
		TreeNode * head;
		if (p.size() == 0) return NULL;
		head = new TreeNode(p[0]);
		TreeNode * cur,*prev=head;
		for (int i = 1; i < p.size(); i++) {
			cur = head;
			while (cur!=NULL) {
				prev = cur;
				if (p[i] < cur->val) {
					cur = cur->left;
				}
				else {
					cur = cur->right;
				}
			}
			if (p[i] < prev->val) {
				prev->left = new TreeNode(p[i]);
			}
			else {
				prev->right = new TreeNode(p[i]);
			}
		}
		return head;
	}
};
int main() {
	Solution sol = Solution();
	vector<int> p = { 8,5,1,7,10,12 };
	sol.bstFromPreorder(p);
	return 0;
}