# 560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.  

연속된 숫자들의 합을 k값과 같이 만들수 있는 부분배열의 개수를 구하는 문제    

**Examples:**   
```
Input:nums = [1,1,1], k = 2  
Output: 2   
```

## trial1
### Intuition
```
1.  이중 for문을 이용해서 모든 인자에 대해서 합이 k를 만족하는지 확인하는 방법이다.  
```
### Codes  
```cpp
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			int tot = 0;
			for (int j = i; j < nums.size(); j++) {
				tot += nums[j];
				if (tot == k) cnt++;
			}
		}
		return cnt;
	}
};
```

### Results (Performance)  
**Runtime:** 480 ms  
**Memory Usage:** 9 MB  

### Discussion
내가 처음에 구현한 방법은 speed가 매우 느린것을 확인할 수 있다. 다음 방법은 O(n^2)이기 때문이다.  
다른사람의 코드를 살펴보니 unordered_map을 사용해서 더 간단하고 퍼포먼스를 높인 것을 확인 할 수 있었다.  

```cpp
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> M;
		int sum = 0;
		int count = 0;

		M[0] = 1;
		for (size_t i = 0; i != nums.size(); ++i) {
			sum += nums[i];
			if (M.count(sum - k)) {
				count += M[sum - k];
			}
			M[sum] += 1;
		}

		return count;
	}
```
**Runtime:** 28ms  
**Memory Usage:** 13.8 MB  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/subarray-sum-equals-k/
