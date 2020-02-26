#include <iostream>
#include <vector>
#include <stdlib.h>
#pragma warning (disable:4996)
using namespace std;
class Solution {
public:
	void print(string a) {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
		}cout << endl;
	}
	vector<vector<string>> let = {
		{""},
		{""},
		{"a","b","c"},//2
		{ "d","e","f" },//3
		{ "g","h","i" },//4
		{ "j","k","l" },//5
		{ "m","n","o" },//6
		{ "p","q","r","s" },//7
		{ "t","u","v" },//8
		{ "w","x","y","z" }//9
	};
	void choose(string digits,int cur,vector<string> &arr,string tmp) {
		if (cur == digits.size()) {//현재 가르키는 digits[cur]이 이미 범위 밖일때
			arr.push_back(tmp);
			//print(tmp);
		}
		else {//아닌경우 더 진행하기
			int whtchar = digits[cur] - '0';
			for (int i = 0; i < let[whtchar].size(); i++) {
				string backup = tmp;
				tmp = tmp + let[whtchar][i];
				choose(digits, cur + 1, arr, tmp);
				tmp = backup;
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		string tmp = "";
		vector<string> arr;
		if (digits == "") {
			return arr;
		}
		else {
			choose(digits, 0, arr, tmp);
			return arr;
		}
	}
};

int main() {
	string digits = "";
	Solution sol = Solution();
	sol.letterCombinations(digits);
	return 0;
}
