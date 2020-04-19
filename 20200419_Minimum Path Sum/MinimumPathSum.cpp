#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& g) {
		int xx[4] = { -1,0 }, yy[4] = { 0,-1 };
		int ny, nx,mi;
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < g[i].size(); j++) {
				mi = INT_MAX;
				for (int z = 0; z < 2; z++) {//위와 왼쪽중 작은 값 구하기
					ny = i + yy[z];
					nx = j + xx[z];
					if (nx >= 0 && nx < g[0].size() && ny >= 0 && ny < g.size()) {
						mi = min(g[ny][nx], mi);
					}
				}
				mi = (mi == INT_MAX ? 0: mi);
				g[i][j] = mi+g[i][j];
			}
		}
		return g.back().back();
	}
};

int main() {
	Solution sol = Solution();
	/*
	{1,3,1},
	{1,5,1},
	{4,2,1}
	};*/
	vector<vector<int>> g = {
		{1,2,5},{3,2,1} };
	cout << sol.minPathSum(g);
	return 0;
}