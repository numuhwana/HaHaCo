# 15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.  

**Note:**
The solution set must not contain duplicate triplets.  

**Example1:**   
```
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## trial1
### Intuition
```
1.  포인터를 세개를 이용하여 구현하였다.
2. low와 high 그리고 현재 인덱스 i가 있다.
3. low는 두번째 요소를 가르키고 high는 세번째 요소를 가리킨다.
4. 중복을 없애기 위해서 각 인덱스(i,low,high) 마다 같은 숫자가 나올때마다 ++를 해주거나 --를 해준다.
5. i가 0보다 커지는 경우는 더이상 3sum을 찾을수 없다는 뜻이므로 반환한다.
6. 현재 값들의 합이 0보다 큰경우에는 high에 --를 해주고 0보다 작은경우에는 low를 ++해준다.

1. This code is implemented three pointers.
2. There are low and high and the current index i.
3. low points to the second element and high points to the third element.
4. To eliminate duplicates, do ++ or-whenever the same number appears for each index (i, low, high).
5. If i becomes greater than 0, it means that 3sum cannot be found anymore, so return.
6. If the sum of the current values ​​is greater than 0,-is set to high, and if less than 0, ++ is set to low.
```
### Codes  
```cpp
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> res;
		int low = 0, high = 0;
		for (int i = 0; i+2 < nums.size() && nums[i] <= 0; i++) {
			low = i+1;
			high = nums.size() - 1;
			while (low < high) {
				if (nums[i] + nums[low] + nums[high] == 0) {
					res.push_back({ nums[i],nums[low],nums[high] });
					while (low < high && nums[high] == nums[high - 1]) {
						high--;
					}
					while (low < high && nums[low + 1] == nums[low]) {
						low++;
					}
					high--;
					low++;
				}
				else if (nums[i] + nums[low] + nums[high] > 0) {
					high--;
				}
				else {
					low++;
				}
			}
			while (i+2 < nums.size() && nums[i] <= 0 && nums[i] == nums[i + 1]) {
				i++;
			}
		}
		return res;
	}
};
```

### Results (Performance)  
**Runtime:**  140 ms         
**Memory Usage:** 12.3 MB

<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (LeetCode)  
https://leetcode.com/problems/3sum/