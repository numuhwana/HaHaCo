#include <iostream>
#include <vector>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) return 0;
		int dia = 0,mx=0;
		vector<TreeNode*> st;
		TreeNode *cur;
		st.push_back(root);
		int i = 0;
		while (i<st.size()) {//위에서부터 left -> right 순서대로 vector에 집어 넣기
			cur = st[i];
			if (cur->left != NULL) {
				st.push_back(cur->left);
			}
			if (cur->right != NULL) {
				st.push_back(cur->right);
			}
			i++;
		}
		while (!st.empty()) {//st를 pop 하면서 진행
			cur = st.back();//가장 밑에 있는 node부터 진행
			st.pop_back();
			if (cur->left == NULL && cur->right == NULL) {//양쪽 자식 node가 모두 NULL이면 길이 0개인것으로 간주
				cur->val = 0;
			}
			else if (cur->left == NULL) {//right에만 길이 존재하면 길+1한 값을 현재 node의 길의 개수로 저장
				cur->val = cur->right->val + 1;
				mx = cur->val;//local maximum값 확인
			}
			else if (cur->right == NULL) {//left에만 길이 존재하면 left의 길+1한 값을 현재 node의 길의 개수로 저장
				cur->val = cur->left->val + 1;
				mx = cur->val;//local maximum 값
			}
			else {
				mx = cur->right->val + cur->left->val + 2;//양쪽 node 모두 길이 존재하면 모든 길의 개수의 합 + 각각 1씩 더하여 local mx값으로 지정
				cur->val = (cur->left->val <= cur->right->val ? cur->right->val + 1: cur->left->val + 1);// 양쪽 길 중에 길이가 긴 길값을 현재 node의 길값으로 지정
			}
			if (dia < mx) dia = mx;//dia는 maximum 길의 개수값
		}
		return dia;
	}
};
TreeNode* makeNode(vector<int> a) {
	int i = 0;
	TreeNode *root = new TreeNode(a[i]),*cur;
	i++;
	vector<TreeNode*> tree;
	tree.push_back(root);
	while (!tree.empty() && i<a.size()) {
		cur = tree.back();
		tree.pop_back();
		if (a[i] != NULL) {
			cur->left = new TreeNode(a[i]);
			i++;
			if (i < a.size()) {
				cur->right = new TreeNode(a[i]);
				i++;
				tree.push_back(cur->right);
			}
			tree.push_back(cur->left);
		}
		else i++;
	}
	return root;
}

int main() {
	vector<int> a = { 1,2,3,4,5,6 };
	TreeNode *root = makeNode(a);
	Solution sol = Solution();
	cout<<sol.diameterOfBinaryTree(root);
}