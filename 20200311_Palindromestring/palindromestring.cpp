#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int mx = 0;
	string ans = "";
	bool update = true;
	string sub = "";
	string longestPalindrome(string s) {
		for (int i = 0; i < s.size()-mx; i++) {
			sub="";
			for (int j = i; j < s.size(); j++) {
				sub += s[j];
				if (mx < sub.size()) {
					update = true;
					for (int j = 0; j < sub.size() / 2; j++) {
						if (sub[j] != sub[sub.size() - j - 1]) {
							update = false;
							break;
						}
					}
					if (update) {
						ans = sub;
						mx = sub.size();
					}
				}
			}
		}
		return ans;
	}
};
int main() {
	string s = "cbbd";
	Solution sol = Solution();
	cout<<sol.longestPalindrome(s);
	return 0;
}