#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> a(text1.size()+1,vector<int>(text2.size()+1,0));
		int i, j;
		text1 = " " + text1;
		text2 = " " + text2;
		for (i = 1; i < a.size(); i++) {
			for (j = 1; j < a[i].size(); j++) {
				if (text1[i] == text2[j]) {
					a[i][j] = a[i - 1][j - 1] + 1;
				}
				else {
					a[i][j] = max(a[i - 1][j], a[i][j - 1]);
				}
			}
		}
		return a[i - 1][j - 1];
	}
};
int main() {
	Solution sol = Solution();
	cout<<sol.longestCommonSubsequence("abc", "def");
	return 0;

}