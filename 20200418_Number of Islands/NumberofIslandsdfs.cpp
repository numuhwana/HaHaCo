#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
void print(vector<vector<char>> g) {
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}cout << endl;
	}cout << endl;
}
class Solution {
public:
	vector<vector<char>> g;
	int ys, xs;
	int xx[4] = { 1,-1,0,0 }, yy[4] = { 0,0,1,-1 };
	void find(int y, int x) {
		if (x < 0 || x >= xs || y < 0 || y >= ys) return;
		if (g[y][x] == '0') return;
		g[y][x] = '0';
		for (int i = 0; i < 4; i++) {
			find(y + yy[i], x + xx[i]);
		}
		
	}
	int numIslands(vector<vector<char>>& g2) {
		ys = g2.size();
		if (g2.size() == 0)
			return 0;
		xs = g2[0].size();
		g = g2;
		int cnt = 0;
		for (int i = 0; i < ys; i++) {
			for (int j = 0; j < xs; j++) {
				if (g[i][j] == '1') {
					cnt++;
					find(i, j);
				}
			}
		}
		return cnt;
	}
};
int main() {
	Solution sol = Solution();
	vector<vector<char>> g = {
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','0','1','1'}
	};
	vector<vector<char>> g = { {'1'},{'1'} };
	cout << sol.numIslands(g);
	return 0;
}