#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& arr) {
		sort(arr.begin(), arr.end());
		vector<vector<int>> ans;
		int st=0,lst=0,cur=0;
		for (int i = 0; i < arr.size();) {
			cur = i;
			lst = arr[cur][1];
			i++;
			while (i < arr.size() && lst>=arr[i][0]) {
				if (lst < arr[i][1]) { lst = arr[i][1]; }
				i++;
			}
			ans.push_back({ arr[cur][0],lst });
		}
		return ans;
	}
};
void print(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout <<"("<< arr[i][0] << "," << arr[i][1] << ") ";
	}
}
int main() {
	//vector<vector<int>> arr = { {1,3},{2,6},{5,7},{8,10},{15,18} };
	//vector<vector<int>> arr = { {1,4},{4,5} };
	//vector<vector<int>> arr = { };
	vector<vector<int>> arr = { {0,0},{1,2},{5,5},{2,4},{3,3},{5,6},{5,6},{4,6},{0,0},{1,2},{0,2},{4,5}};
	Solution sol = Solution();
	print(sol.merge(arr));
	return 0;
}