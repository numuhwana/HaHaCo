#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main() {
	freopen("LCS2.txt", "r", stdin);
	string a, b;
	cin >> a;
	cin >> b;
	a = " " + a;
	b = " " + b;
	vector<vector<int>> arr(a.size(), vector<int>(b.size(), 0));

	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j]) {//현재 i번째와 j번째가 같으면 대각선에서 더한다.
				arr[i][j] = arr[i - 1][j - 1]+1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	cout << arr[a.size()-1][b.size()-1]<<endl;
	if (arr[a.size() - 1][b.size() - 1] > 0) {
		int i, j;
		string ans;
		for (i = a.size() - 1, j = b.size() - 1; i > 0 && j > 0;) {
			if (arr[i][j] == arr[i - 1][j]) {
				i--;
			}
			else if (arr[i][j] == arr[i][j - 1]) {
				j--;
			}
			else {
				ans.push_back(a[i]);
				i--;
				j--;
			}
		}
		for (int z = ans.size() - 1; z >= 0; z--) {
			cout << ans[z];
		}cout << endl;
	}
	return 0;
}