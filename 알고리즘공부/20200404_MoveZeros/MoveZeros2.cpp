#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int tmp = 0;
		int j = 0;
		for (int i = 0; i < nums.size();i++) {
			if (nums[i] != 0) {//현재값(i번째 nums)이 0이 아닌경우 j번째 있는 값과 swqp을 진행한다. (j는 0이 아닌 숫자가 있어야하는 자리 인덱스)
				tmp = nums[j];
				nums[j] = nums[i];
				nums[i] = tmp;
				j++;//j는 0부터 0이 아닌값들의 개수만큼만 플러스된다.
			}
		}
	}
};
void print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}cout << endl;
}
int main() {
	Solution sol = Solution();
	vector<int> n = { 0,1,0,3,12 };
	//vector<int> n = { 0,0,1 };
	//vector<int> n = { 1 };
	sol.moveZeroes(n);
	print(n);

	return 0;
}