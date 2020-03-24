# 46. Permutations
Given a collection of distinct integers, return all possible permutations.


**Example1:**   
```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

## trial1
### Intuition
```
1.  recursion을 이용해서 rec라는 함수를 만들어서 모든 경우의 수를 구해보았다.
2.  rec 함수에서 p라는 vector가 있는데 p는 선택된 숫자를 집어넣는 바구니라고 생각하면 된다.
3.  n에서 순서가 정해진 채로 모두 뽑혀서 p 벡터에 모두 들어가 있는 상태일 때에는 결과 값인 per vector에 넣어준다.
4.  만약에 뽑히지 않은 요소들이 있다면 for문을 통해서 visit가 false인 요소들만 p에 넣어주어 다음 인덱스에 대하여 recursion을 실행해준다.

1. I created a function called "rec" using recursion to find the number of all cases.
2. In the "rec" function, there is a vector called "p". You can think of "p" as a basket to put the selected number.
3. If all the p-vectors are drawn in the order in which they are ordered in n, the result will be put into the per vector.
4. If there are elements that have not been selected, recursion is executed for the next index by inserting only those elements whose visit is false in p through the for statement.
```
### Codes  
```cpp
class Solution {
public:
	vector<vector<int>> per;
	void rec(int cur,vector<int>& n,vector<int>& p,vector<bool>& visit) {
		if (p.size()== n.size()) {
			per.push_back(p);
		}
		else {
			for (int i = 0; i < n.size(); i++) {
				if (!visit[i]) {
					p.push_back(n[i]);
					visit[i] = true;
					rec(i + 1, n, p, visit);
					p.pop_back();
					visit[i] = false;
				}
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> p;
		vector<bool> visit(nums.size(),false);
		rec(0, nums, p,visit);
		return per;
	}
};
```

### Results (Performance)  
**Runtime:**  12 ms         
**Memory Usage:** 7.3 MB

<p align="center"> 
<img src="./capture.JPG">
</p>


### Discussion
 

### 문제 URL (LeetCode)  
https://leetcode.com/problems/permutations/