#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(vector<pair<int, int>> seed,string s) {
	string ss;
	for (int i = 0; i < seed.size(); i++) {
		ss = "";
		for (int j = seed[i].first; j <= seed[i].second; j++) {
			ss += s[j];
		}
		cout << ss<< " ";
	}cout << endl;
}
class Solution {
public:
	int countSubstrings(string s) {
		vector<pair<int,int>> seed;
		int j = 0;
		int i = 0;
		int mx = 1,idx=0;
		for (; i < s.size(); i++) {
			seed.push_back(make_pair(i,i));
			if (j != i && s[j]==s[i]) {
				seed.push_back(make_pair(j, i));
				mx = 2;
			}
			j = i;
		}
		int nf = 0, ns = 0;
		for (i = 0; i < seed.size(); i++) {
			nf = seed[i].first - 1, ns = seed[i].second + 1;
			if (nf >= 0 && ns < s.size() && s[nf]==s[ns]) {
				seed.push_back(make_pair(nf, ns));
				
			}
		}
		print(seed, s);
		return seed.size();
	}
};
int main() {
	string s = "abbaacaa";
	Solution sol = Solution();
	cout<<sol.countSubstrings(s);
	return 0;
}