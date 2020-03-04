#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> arr;
		arr.push_back(0);
		if (num == 0) return arr;
		arr.push_back(1);
		if (num == 1) return arr;
		int cursize = arr.size();
		while(arr.size()!=num+1){
			for (int i = 0; i < cursize; i++) {
				arr.push_back(arr[i] + 1);
				if (arr.size() == num + 1) return arr;
			}
			cursize = arr.size();
		}
		return arr;
	}
};
void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}cout << endl;
}
void main() {
	Solution sol = Solution();
	print(sol.countBits(25));

}