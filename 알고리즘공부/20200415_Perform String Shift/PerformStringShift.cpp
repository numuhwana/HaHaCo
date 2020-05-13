#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shi) {
		string tmp;
		for (int i = 0; i < shi.size(); i++) {
			tmp = "";
			if (shi[i][0]) {//right shift
				for (int j = s.size() - shi[i][1]; tmp.size() < s.size(); j++) {
					if (j == s.size()) j = 0;
					tmp += s[j];
				}
				s = tmp;
			}
			else {//left shift
				for (int j = 0 + shi[i][1]; tmp.size() < s.size(); j++) {
					if (j == s.size()) j = 0;
					tmp += s[j];
				}
				s = tmp;
			}
		}
		return s;
	}
};
int main() {
	Solution sol = Solution();
	string s = "abc";
	vector<vector<int>> shift = { {0,1},{1,2 } };
	cout<<sol.stringShift(s, shift);
	return 0;
}