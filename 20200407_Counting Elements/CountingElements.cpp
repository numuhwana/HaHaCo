#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int countElements(vector<int>& arr) {
		unordered_map<int, int> m;
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			m[arr[i]]++;
		}
		for (int i = 0; i < arr.size(); i++) {
			auto it = m.find(arr[i]+1);
			if (it != m.end()) {
				cnt++;
			}
		}
		return cnt;
	}
};
int main() {
	Solution sol = Solution();
	vector<int> n = { 1,3,2,3,5,0 };
	cout << sol.countElements(n);

	return 0;
}