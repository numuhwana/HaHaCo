#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (sum % 2 != 0) return false;
		sum /= 2;
		vector<bool> dp(sum + 1, false);
		dp[0] = true;
		for (int n : nums) {
			for (int j = sum; j >= 0; j--) {
				if (j - n >= 0) {
					dp[j] = dp[j] || dp[j - n];
				}
			}
		}
		return dp[sum];
	}
};
int main() {
	//vector<int> a = { -1, 0, 1, 2, -1, -4 };
	vector<int> a = { 1,2,5 };
	Solution sol = Solution();
	sol.canPartition(a);
	return 0;
}