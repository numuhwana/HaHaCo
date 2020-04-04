#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& n) {
		long long lar = -INT_MAX,alllar=-INT_MAX;
		for (int i = 0; i < n.size(); i++) {
			if (lar + n[i] > n[i]) {//현재 값보다 현재 subarray의 large값에 현재값을 더한값이 더 큰경우 (subarray에 요소가 추가되는경우)
				lar += n[i];//현재 값을 large에 더한다.
			}
			else {//아니라면 subarray의 시작인덱스가 다시 업데이트 된다.(subarray의 large값도 다시 시작인덱스의 값으로 갱신)
				lar = n[i];
			}
			if (lar > alllar) {//전체적으로 가장 큰 subaaray의 합을 업데이트
				alllar = lar;
			}
		}
		return alllar;
	}
};
int main() {
	Solution sol = Solution();
	//vector<int> n = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> n = { 31,-41,59,26,-53,58,97,-93,-23,84 };
	cout << sol.maxSubArray(n);
	return 0;
}