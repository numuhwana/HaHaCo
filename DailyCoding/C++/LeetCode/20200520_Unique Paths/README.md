# 62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).  

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).  

How many possible unique paths are there?  

## Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

<p align="center"> 
<img src="./pic.JPG">
</p>

## Example1

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```

## Example2

```
Input: m = 7, n = 3
Output: 28
```

## trial1
### Intuition
```
DP를 사용하여 문제를 해결하였다.
어릴때 길찾기 문제랑 비슷한 방법이였는데 왼쪽에 있는 값과 위에 있는 값을 더해서 현재값을 만드는 방법이다.

DP was used to solve the problem.
It was similar to the wayfinding problem when I was young, but it is a method of adding the value on the left and the value on the top to make the current value.
```
### Codes  
```cpp
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(n, vector<int>(m, 1));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }
        return arr[n - 1][m - 1];
    }
};
```

### Results (Performance)  
**Runtime:**  0 ms O(nm)  
**Memory Usage:** 	6.4 MB  

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (LeetCode)  
https://leetcode.com/problems/unique-paths/