#include <iostream>
#include <cmath>
using namespace std;
/*class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		long long ans=m;
		for (long long i = (long long)m+1; i <= n; i++) {
			if (ans == 0) return 0;
			ans = ans & i;
		}
		return ans;
	}
};*/
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		while (m < n) {  // Remove the last bit 1 until n <= m.
			n &= n - 1;
		}
		return n;
	}
};
int main() {
	Solution sol = Solution();
	cout<<sol.rangeBitwiseAnd(2147483647, 2147483647);
	return 0;
}