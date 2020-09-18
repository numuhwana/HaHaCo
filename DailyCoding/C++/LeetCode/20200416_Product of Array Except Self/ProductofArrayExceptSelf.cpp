#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(),1);
		int lst = 1, st = 1, ridx = 0;
		for (int i = 0; i < nums.size(); i++) {
			res[i] *= st;
			st *= nums[i];
			ridx = nums.size() - 1 - i;
			res[ridx] *= lst;
			lst *= nums[ridx];
		}
		return res;
	}
};
int main() {
	vector<int> n = { 1,2,3,4 };
	Solution sol = Solution();
	sol.productExceptSelf(n);
	return 0;
}