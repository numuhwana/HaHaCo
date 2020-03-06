# 55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.  

Each element in the array represents your maximum jump length at that position.  

Determine if you are able to reach the last index.  

배열에서 현재 index의 값은 jump가 가능한 횟수이고 첫번째 인덱스에서 시작해서 마지막 인덱스로 도달할수 있느냐에 대한 결과를 반환하는 문제이다.     

**Example1:**   
```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.  
```

**Example1:**   
```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

## trial1
### Intuition
```
1.  visit라는 vector을 이용해서 방문이 가능한 index는 모두 true로 만드는 방법을 이용하였다.  
(I used visit vector to convert every value of indexes which can be visited to "true".)  
2. 이중 for 문을 이용하여 구현하였다.  
(This is implemented using a double "for" statement.)  
```
### Codes  
```cpp
class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<bool> visit(nums.size(), false);
		visit[0] = true;
		if (nums.size() == 1) return true;
		for (int i = 0; i < nums.size(); i++) {
			if (visit[i] == false) continue;
			for (int j = 1; j <= nums[i] && i+j<nums.size(); j++) {
				if (i + j == nums.size() - 1) return true;
				visit[i + j] = true;
			}
		}
		return false;
	}
};
```

### Results (Performance)  
**Time Limit Exceeded**    

## trial2
### Intuition
```
1. recursion을 이용하여 모든 방문 가능한 경로 탐색을 진행한다.  
(Using recursion to find a path that can be visited to the last.)  
2. 혹시 하나의 경로에서 true를 반환하게 되면 모든 findlast함수의 결과값은 true 가 된다.  
(If a path returns "true", every findlast function will return true.)  
```
### Codes  
```cpp
class Solution {
public:
	bool findlast(int cur, vector<int> &nums) {
		bool res = false;
		if (cur == nums.size() - 1) {
			return true;
		}
		else {
			for (int i = 1; i <= nums[cur] && cur+i<nums.size(); i++) {
				res = findlast(cur + i, nums);
				if(res) return res;
			}
			return res;
		}
	}
	bool canJump(vector<int>& nums) {
		return findlast(0, nums);
	}
};
```

### Results (Performance)  
**Time Limit Exceeded**   

## trial3
### Intuition
```
1. 마지막으로 사용한 방법은 다음 index를 정해줄때 현재 index에서 가장 멀리까지 점프가 가능한 index로 변환하는 방법이다.  
(The last method used is to convert the index into the index that can be jumped farthest from the current index.)  
```
### Codes  
```cpp
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int mx = 0;
		for (int i = 0; i < nums.size() - 1;) {
			int nxtidx = i;
			for (int j = 1; j <= nums[i]; j++) {
				if (i + j >= nums.size() || nums[i + j] + j + i>=nums.size()-1) return true;
				if (max(nums[i + j] + j + i, mx) != mx) {
					nxtidx = i + j;
					mx = nums[i + j] + j + i;
				}
			}
			if (i == nxtidx) {
				return false;
			}
			else {
				i = nxtidx;//다음 인덱스
			}
		}
		return true;
	}
};
```

### Results (Performance)  
**Runtime:** 8 ms   
**Memory Usage:** 9.2 MB  

### Discussion
이 문제에서 가장 중요했던 점은 가장 멀리까지 갈수 있는 index를 찾아내어 다음 index로 지정하는 것이 핵심이었다. 다른사람이 푼 방법중 아래의 방법은 내가 현재 푼 방법의 150%정도 빠른 속도이다. 밑의 코드는 어디까지 도달 가능한 index 변수를 reach 로 지정하여 최대 도달 가능한 값이 nums 배열의 크기보다 큰지 작은지 비교하여 결과값을 반호나한다.     

(The most important thing in this problem was to find the index that can go the farthest and then set it as the next index. The method below got the speed faster than mine. The following code sets the reachable index variable "reach" and get th result by comparing whether the maximum reachable value is larger or smaller than the size of the nums array.)  

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int reach = 0;
        int n =nums.size();
        for(int i =0; i<nums.size()-1 && i<=reach; i++)
        {
            reach = max( reach, i+ nums[i]);
        }
        return ( reach >=n-1);
    }
};
```
**Runtime:** 4 ms    

### 문제 URL (LeetCode)  
https://leetcode.com/problems/jump-game/
