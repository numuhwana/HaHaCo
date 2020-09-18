# 240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:  

Integers in each row are sorted in ascending from left to right.  
Integers in each column are sorted in ascending from top to bottom.    

**Note:**

The input string length won't exceed 1000.

**Example1:**   
```
Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
```

## trial1
### Intuition
```
1.  첫번째 방법은 각 row에 대해서 BST를 사용하여 target을 찾는 방법이다.

1.  The first method is to find the target using BST for each row.
```
### Codes  
```cpp
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
```

### Results (Performance)  
**Runtime:** 328 ms     
**Memory Usage:** 12.3 MB  

<p align="center"> 
<img src="./capture.JPG">
</p>
위에서 사용한 방법은 모든 row에 대해서 BST를 통해 target을 구하는 방법으로 O(nlogn)이 걸리게 된다.  

The method used above takes O (nlogn) as a method of obtaining the target through BST for all rows.  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/search-a-2d-matrix-ii/