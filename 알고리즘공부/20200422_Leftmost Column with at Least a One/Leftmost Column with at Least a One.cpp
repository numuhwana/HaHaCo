#include <iostream>
#include <vector>
using namespace std;
  // This is the BinaryMatrix's API interface.
  // You should not implement it, or speculate about its implementation
 class BinaryMatrix {
  public:
	 /* vector<vector<int>> arr= {
	{0,0,1,1,1,1,1},
	{0,1,1,1,1,1,1},
	{0,0,0,1,1,1,1},
	{0,0,0,1,1,1,1},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1},
	{0,0,0,1,1,1,1}
	  };*/
	  vector<vector<int>> arr = {
	{0,0},{0,1}
	  };
	  int get(int x, int y) {
		  return arr[y][x];
	  };
	  vector<int> dimensions() {
		  vector<int> a;
		  a.push_back(arr.size());
		  a.push_back(arr[0].size());
		return a;
	  };
 };
class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &b) {
		vector<int> a = b.dimensions();
		int y = a[0], x = a[1];
		int j = x - 1, i = 0;
		int cur;
		while (i < y) {
			cur = b.get(i, j);
			if (cur == 1) {
				while (1 <= j && cur == 1) {
					j--;
					cur = b.get(i, j);
				}
				if (cur == 1) return 0;
				else {
					j++;
				}
			}
			i++;
		}
		cur = b.get(i - 1, j);
		if (j == x - 1 && cur == 0) return -1;
		return j;
		
	}
};
int main() {
	BinaryMatrix b = BinaryMatrix();
	Solution sol = Solution();
	cout<<sol.leftMostColumnWithOne(b);

}