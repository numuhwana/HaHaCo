#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> fst(nums.size(),0), snd(nums.size(),0);
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				fst[i]=nums[i];
			}
			else if (i == 1) {
				snd[i]=nums[i];
			}
			else if(i==2){
				fst[i] = fst[i - 2] + nums[i];
			}
			else {
				if (fst[i - 3] + nums[i] > fst[i - 2] + nums[i]) {
					fst[i] = fst[i - 3] + nums[i];
				}
				else {
					fst[i] = fst[i - 2] + nums[i];
				}
				if (snd[i - 3] + nums[i] > snd[i - 2] + nums[i]) {
					snd[i] = snd[i - 3] + nums[i];
				}
				else {
					snd[i] = snd[i - 2] + nums[i];
				}
			}
			if (fst[i] > max) max=fst[i];
			if (snd[i] > max) max = snd[i];
		}
		 return max;
	}
};
int main() {
	vector<int> arr = { 2, 1, 1, 2, 3, 1 };
	vector<int> arr2 = {2,1,1,2,3,3 };
	Solution sol = Solution();
	cout<<sol.rob(arr2);
	return 0;
}