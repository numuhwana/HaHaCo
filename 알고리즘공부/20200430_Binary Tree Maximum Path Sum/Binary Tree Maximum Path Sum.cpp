#include <iostream>
#include <vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
	vector<TreeNode*> v;
	int maxPathSum(TreeNode* root) {
		TreeNode * cur = root,lft,rgt;
		int i = 0;
		v.push_back(cur);
		for (; i < v.size(); i++) {
			cur = v[i];
			if(cur->left!=NULL) v.push_back(cur->left);
			if (cur->right != NULL) v.push_back(cur->right);
		}
		int largest = INT_MIN;
		int both = 0,sum=0;
		while (!v.empty()) {
			cur = v.back();
			v.pop_back();
			if (cur->right != NULL && cur->left != NULL) {
				both = cur->val + cur->left->val + cur->right->val;
				sum = (cur->left->val < cur->right->val ? cur->right->val : cur->left->val);
				cur->val =((sum+cur->val)<=cur->val?cur->val:sum+cur->val);
				if (largest < both) largest = both;
			}
			else if (cur->left != NULL) {
				if (cur->val < (cur->val + cur->left->val))
					cur->val += cur->left->val;
			}
			else if (cur->right!=NULL) {
				if (cur->val < (cur->val + cur->right->val))
					cur->val += cur->right->val;
			}
			if (largest < cur->val) largest = cur->val;
		}
		return largest;
	}
};
TreeNode* maketree(vector<int> v) {
	TreeNode *cur, *head;
	vector<TreeNode*> v2;
	head = new TreeNode(v[0]);
	v2.push_back(head);
	int idx = 0;
	for (int i = 1; i < v.size();i++) {
		if (v[i] != 0) {
			if (i % 2 == 0) {
				idx = (i - 1) / 2;
				cur = v2[idx];
				cur->right = new TreeNode(v[i]);
				v2.push_back(cur->right);
			}
			else {
				idx = i / 2;
				cur = v2[idx];
				cur->left = new TreeNode(v[i]);
				v2.push_back(cur->left);
			}
		}
	}
	return head;
}
int main() {
	Solution sol = Solution();
	vector<int> v = { 2,-1,-2 };
	TreeNode * h=maketree(v);
	cout<<sol.maxPathSum(h);
	return 0;
}