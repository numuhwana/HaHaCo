#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, bool> m;
		int p = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			p ^= nums[i];
		}
		return p;
	}
};
int main() {
	Solution sol = Solution();
	vector<int> n = { 2,2,1 };
	cout<<sol.singleNumber(n);
	return 0;
}