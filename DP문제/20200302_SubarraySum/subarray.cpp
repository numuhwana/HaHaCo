#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			int tot = 0;
			for (int j = i; j < nums.size(); j++) {
				tot += nums[j];
				if (tot == k) cnt++;
			}
		}
		return cnt;
	}
};
int main() {
	Solution sol = Solution();
	vector<int> arr = { -1,-1,1 };
	vector<int> arr1 = { 1,2,3 };
	cout<<sol.subarraySum(arr1, 3);
	return 0;
}