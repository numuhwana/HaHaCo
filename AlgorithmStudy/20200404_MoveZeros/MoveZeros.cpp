#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int plus = nums.size();
		for (int i = 0; i < plus; i++) {
			if (nums[i] == 0) {
				plus--;
				nums.erase(nums.begin() + i);//erase로 지우고
				nums.push_back(0);//뒤에 push back 하기
				if (nums[i] == 0) i--;//현재값이 0이라면 현재값에 대한 loop를 돌아야함
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
	sol.moveZeroes(n);
	print(n);

	return 0;
}