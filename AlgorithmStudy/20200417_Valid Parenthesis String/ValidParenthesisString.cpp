#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool checkValidString(string s) {
		vector<int> lft;
		vector<int> star;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				lft.push_back(i);
			}
			else if (s[i] == '*') {
				star.push_back(i);
			}
			else if(!lft.empty()){
				lft.pop_back();
			}
			else if(!star.empty()){
				star.pop_back();
			}
			else {
				return false;
			}
		}
		while (!lft.empty()) {
			if (star.empty() || star.back() < lft.back()) {
				return false;
			}
			else {
				star.pop_back();
				lft.pop_back();
			}
		}
		return true;
	}
};
int main() {
	Solution sol = Solution();
	string s = "(";
	cout<<(sol.checkValidString(s)?"True":"False");
	return 0;
}