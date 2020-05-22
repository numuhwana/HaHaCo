#include <iostream>
#include <vector>
#include <string>
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
	  bool isValidSequence(TreeNode* root, vector<int>& arr) {
		  return find(root, arr, 0);
	  }
	  bool find(TreeNode* cur, vector<int>& arr,int idx) {
		  bool res=false;
		  if (idx < arr.size()) {
			  if (cur->val == arr[idx]) {
				  if (cur->left == NULL && cur->right == NULL) { 
					  return (idx == arr.size() - 1 ? true : false);
				  };
				  if (cur->left != NULL) { res = find(cur->left, arr, ++idx);
				  idx--;
				  }
				  if (cur->right != NULL) {
					  idx++;
					  res = (res ? true : find(cur->right, arr, idx));
				  idx--;
				  }
				  return res;
			  }
			  else {
				  return false;
			  }
		  }
		  else {
			  return false;
		  }
		  
	  }
  };

TreeNode* maketree(vector<int> v) {
	TreeNode *cur, *head;
	vector<TreeNode*> v2;
	head = new TreeNode(v[0]);
	v2.push_back(head);
	int idx = 0;
	for (int i = 1; i < v.size();i++) {
		//if (v[i] != NULL) {
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
		//}
		/*else {
			v2.push_back(NULL);
		}*/
	}
	return head;
}
/*
[4,null,2,7,5,3,4,4]
[4,2,7,4]*/
int main() {
	Solution sol = Solution();
	vector<int> v = { 0,1,0,0,1,0,NULL,NULL,1,0,0 };
	TreeNode * h=maketree(v);
	vector<int> v2 = { 0,1,0,1 };
	cout<<(sol.isValidSequence(h,v2)?"True":"False");
	return 0;
}