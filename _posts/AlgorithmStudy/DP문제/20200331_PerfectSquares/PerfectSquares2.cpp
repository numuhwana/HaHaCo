#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		static vector<int> memo(1, 0);//0번째 초기화
		int i, mi;
		while (memo.size() <= n) {//memo에 n만큼의 값을 모두 계산 했을 때
			i = memo.size();
			mi = n;
			for (int j = 1; j*j <= i; j++) {//현재까지 만들어진 숫자보다 작은 모든 square에 대해서 진행하기
				mi = min(mi, memo[i - j * j] + 1);//현재값에서 square값을 뺀 인덱스의 count에 1더한값과 현재 count 값과 비교하여 작은값 넣어주기
			}
			memo.push_back(mi);//모든 square에 대해서 값을 구해주면 memo에 삽입(memo 안에는 가장 작은 count들이 나열되게 된다.)
		}
		return memo[n];
	}
};
int main() {
	Solution sol = Solution();
	cout<<sol.numSquares(12);
	return 0;
}