#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cctype>
#include <queue>
using namespace std;
class Solution {
public:
	void decode(vector<int>& nums, vector<int> &left, vector<int> &right,string s,string &sub) {
		string str;
		int num = nums.back();
		left.pop_back();
		nums.pop_back();
		right.pop_back();
		string tmp=sub;
		for (int z = 1; z < num; z++) {
			sub += tmp;
		}	
	}
	string decodeString(string s) {
		if (s.size() > 0) {
			vector<int> right;
			vector<int> left;
			vector<int> nums;
			vector<string> sub;
			sub.push_back("");//초기화
			string num;
			string res;
			for (int i=0; i<s.size(); i++) {
				if (isdigit(s[i])) {
					num += s[i];
				}
				else if (s[i] == '[') {//왼쪽 브라켓 나온경우 숫자 vector에 집어넣고 브라켓 집어넣고
					string ss = "";
					nums.push_back(atoi(num.c_str()));
					num = "";
					left.push_back(i);
					sub.push_back(ss);
				}
				else if (s[i] == ']') {//오른쪽 브라켓이면 하나씩 추가
					right.push_back(i);
					decode(nums, left, right, s,sub.back());
					string ss = sub.back();
					if (sub.size() > 1) {
						sub.pop_back();
						sub.back() += ss;
					}
				}
				else {
					sub.back() += s[i];
				}
			}
			return sub.back();
		}
		else {
			return "";
		}
	}
};
int main() {
	Solution sol = Solution();
	string str1 = "3[a2[c]e]2[bc]";
	string str2 = "2[d10[e]]3[x2[r2[b]]k]";
	string str3 = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
	string str4 = "2[2[y]q4[a2[jk]e1[f]]]ef";
	string str5 = "leetcode";
	string str=sol.decodeString(str4);
	return 0;
}