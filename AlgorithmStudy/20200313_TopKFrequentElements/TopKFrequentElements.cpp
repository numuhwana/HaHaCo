#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> rank;
		int cur = nums[0],cnt=1;
		for (int i = 0; i < nums.size(); i++,cnt++) {
			if (cur != nums[i]) {
				rank.push(make_pair(cnt, cur));
				cur = nums[i];
				cnt = 0;
			}
		}
		rank.push(make_pair(cnt, cur));
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(rank.top().second);
			rank.pop();
		}
		return ans;
	}
};
void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}
int main() {
	//vector<int> arr = { 1, 1, 1, 2, 2, 3 };
	vector<int> arr = { -1,-1};
	int p = 1;
	Solution sol = Solution();
	print(sol.topKFrequent(arr, p));
	return 0;
}