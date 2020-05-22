#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() > 0) {
			int i = 0;
			if (nums.size() == 1) { if (nums[i] != target) return -1; }
			while (nums[i] != target) {
				if (nums[i] > target) {//현재가 클때 왼쪽 이동
					int p = i;
					if (i - 1 <0) { i = nums.size() - 1; }
					else { i--; }
					if (nums[i] < target) return -1;//사이에 값이 없는경우 target은 없는것으로 간주
					if (nums[i] > nums[p]) return -1;//이미 주어진 array의 한바퀴를 다 돌은 상태인경우
				}
				else {//현재보다 작을때 오른쪽 이동
					int p = i;
					if (i + 1 >= nums.size()) { return -1; }//이미 값이 없는것
					else { i++; }
					if (nums[i] > target) return -1;//사이에 값이 없는경우 target은 없는것으로 간주
					if (nums[i] < nums[p]) return -1;//이미 주어진 array의 한바퀴를 다 돌은 상태인경우
				}
			}
			return i;
		}
		return -1;
	}
};
int main() {
	Solution sol = Solution();
	vector<int> ex = { 4,5,6,7,0,1,2 };
	int target = 3;
	cout<<sol.search(ex, target)<<endl;
	return 0;
}