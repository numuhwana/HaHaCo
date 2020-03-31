#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		vector<int> memo(n+1, n);
		vector<int> ps;
		double tmp = 0;
		int j = 0,i;
		for (i = 1; i <= n; i++) {
			tmp = sqrt(i);
			if ((tmp - floor(tmp)) == 0) {//square이라면
				memo[i] = 1;
				ps.push_back(i);//perfect square 목록에 넣기
			}
		}
        int val=0;
		for (i = 2; i <= n; i++) {
            tmp = sqrt(i);
			if ((tmp - floor(tmp)) != 0) {//square가 아닌경우에만 진행
                for (j = 0;j < ps.size() && ps[j]<i; j++) {//모든 square에 대해서 구함
                    val=(memo[i - ps[j]] + 1);
                    memo[i] = (val > memo[i] ? memo[i] : val);
                }
            }
		}
		return memo[n];
	}
};
int main() {
	Solution sol = Solution();
	cout<<sol.numSquares(13);
	return 0;
}