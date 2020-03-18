# 56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.  

**Note:**

The input string length won't exceed 1000.

**Example1:**   
```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example2:**   
```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

## trial1
### Intuition
```
1.  첫번째 방법은 현재 인덱스와 다음 인덱스를 비교하여 i번째 값의 2번째 요소가 i+1번째 값의 1번째 요소보다 크거나 같은 경우에 merge가 일어나도록 하였다.
2.  merge가 일어나야 하는 경우에 i번째 값의 2번째 요소가 i+1번째 값의 1번째 요소의 값보다 큰 경우에는 i번째 값으로 merge가 일어나도록 한다.
3.  그 후에는 i+1번째 값을 없애고 인덱스는 다시 i번째부터 시작하도록 한다.

1. In the first method, the current index is compared with the next index so that merge occurs when the second element of the i-th value is greater than or equal to the first element of the i + 1-th value.
2. When the second element of the i-th value is greater than the value of the first element of the i + 1th value when the merge should occur, the merge is performed with the i-th value.
3. After that, the i + 1th value is removed and the index starts from the ith again.
```
### Codes  
```cpp
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& arr) {
		sort(arr.begin(), arr.end());
		for (int i = 0; i+1 < arr.size(); i++) {
			if (arr[i][1] >= arr[i + 1][0]) {
				if (arr[i][1] < arr[i + 1][1]) {
					arr[i][1] = arr[i + 1][1];
				}
				arr.erase(arr.begin() + i + 1);
				i--;
			}
		}
		return arr;
	}
};
```

### Results (Performance)  
**Runtime:**  956 ms       
**Memory Usage:** 11.4 MB  

<p align="center"> 
<img src="./capture.JPG">
</p>
위에서 사용한 방법은 runtime이 너무 많이 걸리게 된다. 그 이유는 merge가 일어날때마다 vector 안에 값을 삭제하는 과정에서 iterator을 돌려주기 때문인 것 같다.  

The method used above takes too much runtime. The reason seems to be that it executes an iterator in the process of deleting the value in the vector whenever a merge occurs.  


## trial2
### Intuition
```
1.  두번째 방법은 최종적인 두번째 요소값을 while문을 통해서 찾아주어 merge를 진행하는 방법이다.
2.  lst라는 변수를 사용하여 최종적인 두번째 요소값을 저장해준다. 비교할 인덱스의 첫번째 요소값이 lst보다 작거나 같은경우 merge가 발생하게 된다.
3.  최종적으로 lst 값이 결정되는 경우에는 ans vector에 처음 값의 첫번째 요소와 lst를 묶어서 같이 삽입하게 된다.

1. The second method is to find the final second element value through the while statement to merge elements.
2. The final second element value is stored using the variable "lst". If the value of the first element of the index to be compared is less than or equal to "lst", merge occurs.
3. When the value of "lst" is finally determined, the first element of the pivot value("cur" variable) in vector and "lst" are bundled and inserted together in the "ans" vector.
```
### Codes  
```cpp
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& arr) {
		sort(arr.begin(), arr.end());
		vector<vector<int>> ans;
		int lst=0,cur=0;
		for (int i = 0; i < arr.size();) {
			cur = i;
			lst = arr[cur][1];
			i++;
			while (i < arr.size() && lst>=arr[i][0]) {
				if (lst < arr[i][1]) { lst = arr[i][1]; }
				i++;
			}
			ans.push_back({ arr[cur][0],lst });
		}
		return ans;
	}
};
```

### Results (Performance)  
**Runtime:** 20 ms     
**Memory Usage:** 11.6 MB  

<p align="center"> 
<img src="./capture2.JPG">
</p>
위에서 사용한 방법은 첫번째 trial에 비해 runtime이 많이 상승하였다. 그 이유는 vector의 함수중 하나인 erase의 호출이 없었기 때문이라고 생각한다. 위의 방법은의 runtime은 O(n)이다. 

The method used above has a much higher runtime than the first trial. I think the reason is that there was no call of erase, one of the functions of vector. The runtime of the above method is O (n).

### Discussion
이 문제를 풀면서 깨달은 점은 for문에서 첫번째 세미콜론 뒤에 오는 조건문에서 ```i+1<arr.size() 와 i<arr.size()-1```는 다르게 작동한다는 점이다. 원래는 +와 -이 부등호보다 우선순위가 높은것으로 알고 있었지만 코드를 실제로 돌려보았을 때는 좌측에 있던 연산자 먼저 계산을 하여 ```i<arr.size()-1와 같은 경우에는 i<arr.size()```를 먼저 계산하는 것 같았다.  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/merge-intervals/