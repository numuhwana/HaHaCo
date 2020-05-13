#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& mat, int target) {
		bool ex = false;
		int S,i=0,L,p;
		for (; i < mat.size(); i++) {
			L = mat[i].size() - 1, S = 0;
			while (L>=S) {
				p = floor((double(L + S) / 2));
				if (mat[i][p] < target) {
						S = p+1;
				}
				else if (mat[i][p] > target) {
						L = p-1;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
};
int main() {
	vector<vector<int>> mat = {
	{1,   4,  7, 11, 15 },
	{2,   5,  8, 12, 19},
	{3,   6,  9, 16, 22 },
	{10, 13, 14, 17, 24},
	{18, 21, 23, 26, 30}
	};
	Solution sol = Solution();
	cout << (sol.searchMatrix(mat,18)?"true":"false");
	return 0;
}