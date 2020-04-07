#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> tmp = strs;
		vector<vector<string>> res;
		unordered_map<string, int> m;
		int j = -1;
		for (int i = 0; i < strs.size(); i++) {
			sort(tmp[i].begin(), tmp[i].end());//단어에 대한 반복문 돌리기
			auto it = m.find(tmp[i]);
			if (it == m.end()) {//새로운 단어일때
				j++;
				m[tmp[i]] = j;
				res.push_back({ strs[i] });//세트를 res에 넣기
			}
			else {//단어가 이미 존재할때
				res[it->second].push_back(strs[i]);
			}
		}
		return res;
	}
};
void print(vector<vector<string>> s) {
	for (int i = 0; i < s.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < s[i].size(); j++) {
			cout << "" << s[i][j]<<",";
		}cout << "], " << endl;
	}
}

int main() {
	Solution sol = Solution();
	vector<string> n = { "eat", "tea", "tan", "ate", "nat", "bat" };
	print(sol.groupAnagrams(n));

	return 0;
}