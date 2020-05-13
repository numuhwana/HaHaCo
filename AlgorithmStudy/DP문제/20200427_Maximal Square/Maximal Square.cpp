#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& m) {
		if (m.size() == 0) return 0;
		int size = 0;
		//int a[][] = { 0, };
		vector<vector<int>> a(m.size()+1, vector<int>(m[0].size()+1, 0));
		for (int i = 1; i < a.size(); i++) {
			for (int j = 1; j < a[i].size(); j++) {
				a[i][j] = m[i - 1][j - 1] - '0';
			}
		}
		for (int i = 1; i < a.size(); i++) {
			for (int j = 1; j < a[i].size(); j++) {
				if(a[i][j]==1) {
					a[i][j] = min(a[i - 1][j], min(a[i - 1][j-1], a[i][j-1]))+1;
					if (a[i][j] > size) size = a[i][j];
				}
			}
		}
		return size*size;
	}
};
int main() {
	vector<vector<char>> m = {
	{ '1', '0', '1', '0' ,'0'},
	{ '1' ,'0', '1', '1' ,'1'},
	{ '1', '1', '1', '1', '1'},
	{ '1', '0', '1', '1', '1'}
	};
	Solution sol = Solution();
	 cout<<sol.maximalSquare(m);
	return 0;
}