#include <iostream>
#include <vector>
#include <string>
#pragma warning (disable:4996)
using namespace std;

vector<string> solution(int n,vector<string> v) {
	vector<string> ans;
	for (int i = 0; i < n; i++) {
		int lft = 0;
		string cur = "YES";
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == '(') {//왼쪽 괄호면
				lft++;
			}
			else if(lft>0){//오른쪽 괄호면
				lft--;
			}
			else {
				cur = "NO";
				break;
			}
		}
		if (lft != 0) {
			cur = "NO";
		}
		ans.push_back(cur);
	}
	return ans;
}
int main() {
	//freopen("괄호.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	cin >> n;
	vector<string> v;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	vector<string> ans=solution(n,v);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}cout << endl;
	return 0;
}