#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		int sum = n;
		int nom, rem = 0;
		unordered_map<int, bool> m;
		while (sum!=1) {//sum이 1이면 
			nom = sum;
			sum = 0;
			while (nom > 0) {//nominator이 0이상일때 각자리수의 power을 진행
				rem = nom % 10;
				sum += pow(rem, 2);
				nom /=10;
			}
			if (m.find(sum) != m.end()) {//map에 더한값이 이미 존재하면 cycle
				return false;
			}
			m[sum] = true;
		}
		return true;
	}
};
int main() {
	Solution sol = Solution();
	int n = 19;
	cout << (sol.isHappy(n)?"True":"Flase");
	return 0;
}