# 448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.  

Find all the elements of [1, n] inclusive that do not appear in this array.  

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.   


## Example1

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

## trial1
### Intuition
```
sort를 먼저 해준 다음 arr[0]에 있는 숫자가 1보다 큰경우 숫자가 존재하지 않는 것이므로 res에 넣어줍니다. 
그리고 그 뒤에 숫자들에 대해서 num[i]와 num[i+1] 사이에 없는 숫자들을 res에 넣어줍니다.
그 후에는 nums의 사이즈보다 nums의 마지막 요소가 작은경우 없는 숫자들을 모두 넣어줍니다.
```
### Codes  
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.size() <= 0) return res;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums[0]; i++) {
            res.push_back(i);
        }
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = 1; j < (nums[i + 1] - nums[i]); j++) {
                res.push_back(nums[i] + j);
            }           
        }
        for (int i = nums[nums.size()-1]+1; i <= nums.size(); i++) {
            res.push_back(i);
        }
        return res;
    }
};
```

### Results (Performance)  
**Runtime:**  200 ms  
**Memory Usage:** 	33.8 MB  


<p align="center"> 
<img src="./capture.JPG">
</p>



### 문제 URL (LeetCode)  
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/