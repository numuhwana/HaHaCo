#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& p) {
		int sum = 0, fst = INT_MAX , sub = 0,snd=-1;
		for (int i = 0; i < p.size(); i++) {
			if (fst < p[i] && snd<p[i]) {
					sub = p[i] - fst;
					snd=p[i];
			}
			else {
				sum += sub;
				fst = p[i];
				sub = 0;
				snd = -1;
			}
		}
		if (sub > 0) sum += sub;
		return sum;
	}
};
int main() {
	Solution sol = Solution();
	vector<int> n = { 7,1,5,3,6,4 };
	//vector<int> n = { 1,2,3,4,5 };
	//vector<int> n = { 2,1,2,0,1 };
	cout<<sol.maxProfit(n);

	return 0;
}