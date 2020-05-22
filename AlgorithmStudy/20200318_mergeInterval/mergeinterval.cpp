class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& arr) {
		sort(arr.begin(), arr.end());
		for (int i = 0; i+1 < arr.size(); i++) {
			if (arr[i][1] >= arr[i + 1][0]) {
				if (arr[i][1] < arr[i + 1][1]) {
					arr[i][1] = arr[i + 1][1];
				}
				arr.erase(arr.begin() + i + 1);
				i--;
			}
		}
		return arr;
	}
};