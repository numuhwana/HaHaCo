#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string s, t;
		int j = 0,i;
		for (i = 0; i < S.size(); i++) {
			if (S[i] != '#') {
				s.push_back(S[i]);
			}
			else if(!s.empty()){
				s.pop_back();
			}
		}
		for (i = 0; i < T.size(); i++) {
			if (T[i] != '#') {
				t.push_back(T[i]);
			}
			else if(!t.empty()){
				t.pop_back();
			}
		}
		return (s == t ? true : false);
	}
};
int main() {
	string S = "a##c"
		,T="#a#c";
	Solution sol = Solution();
	sol.backspaceCompare(S, T);
}