# 198. House Robber
You are a professional robber planning to rob houses along a street.  
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.    

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.  

도둑이 최대한 많은 돈을 벌면서 도둑질 할때 돈의 수를 반환한다. (털린 집의 바로 옆집은 바로 털지 못한다.)  

**Example 1:**
```
**Input:** [1,2,3,1]  
**Output:** 4  
**Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).  
             Total amount you can rob = 1 + 3 = 4.  
```
**Example 2:**
```
**Input:** [2,7,9,3,1]  
**Output:** 12  
**Explanation:** Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).  
             Total amount you can rob = 2 + 9 + 1 = 12.  
```
## trial 1  
### Intuition  
```
1.  permutation 알고리즘을 이용하여 모든 경우의 수를 다 파악한다.  
```
### Codes  
```cpp
class Solution {
public:
	int max = 0;
	void choose(int cur, vector<int> a, vector<int>& nums,int tot) {
		if (cur+2 >= nums.size()) {
			if (max < tot) max = tot;
		}
		else {
			for (int i = 2; i < 4; i++) {
				int ni = cur + i;
				if (ni < nums.size()) {
					a.push_back(nums[ni]);
					tot += nums[ni];
					choose(ni, a, nums,tot);
					a.pop_back();
					tot -= nums[ni];
				}
			}
		}
	}
	int rob(vector<int>& nums) {
		vector<int> a;
		if (nums.size() > 0) {
			a.push_back(nums[0]);
			int tot = nums[0];
			choose(0, a, nums,tot);
			if (nums.size() > 1) {
				a.pop_back();
				tot = nums[1];
				a.push_back(nums[1]);
				choose(1, a, nums,tot);
			}
		}
		return max;
	}
};
```

### Results (Performance)  
**Status:** Time Limit Exceeded  

### Problem
모든 경우의 수를 찾는 방식으로 하면 그 가지수가 n이 커지면 커질수록 너무 많아지기 때문에 알맞은 Time Limit이 뜨게 된다.   

## trial 2  
### Intuition  
```
1.  memoization을 사용하여 0번째 index를 선택했을 경우와 1번째 index를 선택했을 경우를 나눠서 저장한다.  
2. i-2번째의 값과 i-3번재의 값중 i와 더했을때 더 큰값을 배열에 저장하도록 한다.  
3. 배열에 저장된값에서 가장 큰 값을 반환하게 된다.  
```
### Codes  
```cpp
class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> fst(nums.size(),0), snd(nums.size(),0);
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				fst[i]=nums[i];
			}
			else if (i == 1) {
				snd[i]=nums[i];
			}
			else if(i==2){
				fst[i] = fst[i - 2] + nums[i];
			}
			else {
				if (fst[i - 3] + nums[i] > fst[i - 2] + nums[i]) {
					fst[i] = fst[i - 3] + nums[i];
				}
				else {
					fst[i] = fst[i - 2] + nums[i];
				}
				if (snd[i - 3] + nums[i] > snd[i - 2] + nums[i]) {
					snd[i] = snd[i - 3] + nums[i];
				}
				else {
					snd[i] = snd[i - 2] + nums[i];
				}
			}
			if (fst[i] > max) max=fst[i];
			if (snd[i] > max) max = snd[i];
		}
		 return max;
	}
};
```

### Results (Performance)  
**Runtime:** 4 ms  
**Memory Usage:** 8 MB  

### Discussion
다른 사람의 코드를 살펴보니 훨신 더 간결하게 코드를 짤 수 있다는 것을 알았다. 그 예시로 다음 코드가 되겠다. (출처: leetcode)
```cpp
class Solution {
public:
	int rob(vector<int>& nums) {

 int i,n=v.size();
        if(n==0) return 0;
        if(n==1) return v[0];
        if(n==2) return max(v[0],v[1]);
        int A[n];
        A[0]=v[0];
        A[1]=max(v[0],v[1]);
        for(i=2;i<n;i++) A[i]=max((v[i]+A[i-2]),(A[i-1]));
        return A[n-1];

};
```
위의 코드에서는 A라는 배열에 현재 index에 대해서 될수 있는 가장 큰 값을 저장하는 방식으로 작성된 코드이다.  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/house-robber/
