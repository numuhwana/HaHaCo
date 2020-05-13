#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int mx = 0;
		for (int i = 0; i < nums.size() - 1;) {
			int nxtidx = i;
			for (int j = 1; j <= nums[i]; j++) {
				if (i + j >= nums.size() || nums[i + j] + j + i>=nums.size()-1) return true;
				if (max(nums[i + j] + j + i, mx) != mx) {
					nxtidx = i + j;
					mx = nums[i + j] + j + i;
				}
			}
			if (i == nxtidx) {
				return false;
			}
			else {
				i = nxtidx;//다음 인덱스
			}
		}
		return true;
	}
};
void main() {
	vector<int> arr = { 2,3,1,1,4 };
	vector<int> arr2 = { 3, 2, 1, 0, 4 };
	vector<int> arr3 = { 1, 3, 1, 2, 2,2,0,1,4 };
	vector<int> arr4 = { 1,3,2 };
	vector<int> arr5 = { 1,1,1,0 };
	Solution sol = Solution();
	cout << sol.canJump(arr5);
}