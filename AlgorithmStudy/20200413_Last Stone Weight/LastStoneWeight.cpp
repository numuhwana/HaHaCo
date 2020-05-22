#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int, vector<int>, less<int>> p;
		for (int i = 0; i < stones.size(); i++) {
			p.push(stones[i]);
		}
		int a, b;
		while (!p.empty() && p.size() > 1) {
			a = p.top();
			p.pop();
			b = p.top();
			p.pop();
			if (a != b) {
				p.push(abs(a - b));
			}
		}
		return (p.empty() ? 0 : p.top());
	}
};
int main() {
	vector<int> a = { 2,7,4,1,8,1 };
	Solution sol = Solution();
	cout << sol.lastStoneWeight(a);
}