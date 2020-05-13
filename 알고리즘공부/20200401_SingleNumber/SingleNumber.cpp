#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, bool> m;
		int p = 0;
		for (int i = 0; i < nums.size(); i++) {
			if(m.find(num[i])!=m.end()) p += nums[i];
			else p-=nums[i];
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