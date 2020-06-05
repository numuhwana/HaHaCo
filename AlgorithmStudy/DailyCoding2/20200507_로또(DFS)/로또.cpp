#include <iostream>
#include <vector>
//#pragma warning(disable:4996)
using namespace std;
int k, s;
void dfs(int cur,vector<int>& s,vector<int>& ans) {
	if (ans.size() == 6) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i]<<" ";
		}cout << endl;
	}
	else {
		for (int i = cur; i < s.size(); i++) {
			ans.push_back(s[i]);
			dfs(i + 1, s, ans);
			ans.pop_back();
		}
	}
}
int main() {
	//freopen("test.txt", "r", stdin);
	int tmp;
	while (1) {
		cin >> k;
		if (k == 0) return 0;
		vector<int> s;
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			s.push_back(tmp);
		}
		dfs(0, s,ans);
		cout << endl;
	}
	return 0;

}