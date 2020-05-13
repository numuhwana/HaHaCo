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
	int numIslands(vector<vector<char>>& g) {
		int xx[4] = { 1,-1,0,0 }, yy[4] = { 0,0,1,-1 };
		int cnt = 0, nx, ny, x, y;
		if (g.size() == 0) return 0;
		int r = g.size(),c=g[0].size();

		queue<pair<int, int>> q;
		pair<int, int> cur;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (g[i][j] == '1') {
					cnt++;
					x = j; y = i;
					q.push(make_pair(y, x));
					while (!q.empty()) {
						cur = q.front();
						x = cur.second, y = cur.first;
						if (g[y][x] == '1') {
							g[y][x] = '0';
						}
						q.pop();
						for (int z = 0; z < 4; z++) {
							nx = x + xx[z]; ny = y + yy[z];
							if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
								if (g[ny][nx] == '1') {
									q.push(make_pair(ny, nx));
									g[ny][nx]='0';
								}
							}
						}
					}
				}
			}
		}
		return cnt;
	}

};
int main() {
	Solution sol = Solution();
	/*vector<vector<char>> g = {
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','0','1','1'}
	};*/
	vector<vector<char>> g = { {'1'},{'1'} };
	cout << sol.numIslands(g);
	return 0;
}