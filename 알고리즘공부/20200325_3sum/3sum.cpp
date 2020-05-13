#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> res;
		int low = 0, high = 0;
		for (int i = 0; i+2 < nums.size() && nums[i] <= 0; i++) {
			low = i+1;
			high = nums.size() - 1;
			while (low < high) {
				if (nums[i] + nums[low] + nums[high] == 0) {
					res.push_back({ nums[i],nums[low],nums[high] });
					while (low < high && nums[high] == nums[high - 1]) {
						high--;
					}
					while (low < high && nums[low + 1] == nums[low]) {
						low++;
					}
					high--;
					low++;
				}
				else if (nums[i] + nums[low] + nums[high] > 0) {
					high--;
				}
				else {
					low++;
				}
			}
			while (i+2 < nums.size() && nums[i] <= 0 && nums[i] == nums[i + 1]) {
				i++;
			}
		}
		return res;
	}
};
void print(vector<vector<int>> a) {
	for (int i = 0; i < a.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << " ";
		}cout << "]" << endl;
	}cout << endl;
}
int main() {
	//vector<int> a = { -1, 0, 1, 2, -1, -4 };
	vector<int> a = { 0,0,0,0};
	Solution sol = Solution();
	print(sol.threeSum(a));
	return 0;
}