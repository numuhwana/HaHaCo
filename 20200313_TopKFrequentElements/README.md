# 347. Top K Frequent Elements 
Given a non-empty array of integers, return the k most frequent elements.    

**Note:**

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.  
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.  

**Example1:**   
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```
**Example2:**   
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

## trial1
### Intuition
```
1.  이 문제를 풀기 위해서 라이브러리에서 sort와 priority_queue(heap)을 사용하였다.
2.  이때 STL의 sort를 사용하여 정렬을 해주어 중복되는 숫자들을 모아주도록 한다.
3.  priority_queue와 pair을 사용하여 첫번째 요소에 각 숫자들의 개수, 그리고 두번째 요소에는 숫자를 지정해준다. 이때 우선순위는 cnt가 가장 큰 숫자가 가장 top으로 오도록 정렬을 한다.
4.  for 반복문을 실행해 주는데 이 반복문에서는 현재 count를 세고 있는 숫자(cur)와 현재 인덱스의 숫자가 다르다면 현재 count를 세고 있는 숫자(cur)는 nums 배열 안에 더이상 존재하지 않는다는 뜻이 되므로 rank 큐 안에 현재 count와 cur을 저장해주도록 한다.
5.  마지막에는 rank에 이미 정렬이 완료된 상태에서 가장 top에 있는 값들을 k의 개수만큼 ans vector에 넣어주어 반환하면 된다.

1. To solve this problem, sort and priority_queue (heap) are used from library.
2. At this time, sort using STL to collect duplicate numbers.
3. Using priority_queue and pair, specify the count of each number in the first element and the number from "nums" in the second element. At this time, the priority is sorted so that the number with the largest cnt comes to the top.
4. Execute the for loop. In this loop, if the number counting the current count and the number of the current index are different, it means that the current number no longer exists in the "nums" array. Store the current count and cur inside "rank" queue.
5. At the end, you can put the topmost values ​​in the ans vector as many as the number of k values ​​in the rank already sorted.
```
### Codes  
```cpp
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> rank;
		int cur = nums[0],cnt=1;
		for (int i = 0; i < nums.size(); i++,cnt++) {
			if (cur != nums[i]) {
				rank.push(make_pair(cnt, cur));
				cur = nums[i];
				cnt = 0;
			}
		}
		rank.push(make_pair(cnt, cur));
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(rank.top().second);
			rank.pop();
		}
		return ans;
	}
};
```

### Results (Performance)  
**Runtime:** 20 ms   
**Memory Usage:** 9.9 MB  

<p align="center"> 
<img src="./capture.jpg">
</p>

### Discussion
이때 STL에서 sort 알고리즘은 quick sort를 사용하므로 O(nlogn)의 시간복잡도를 가지고 있다. priority_queue는 힙 기반으로 데이터를 삽입할때에는 O(logn)의 시간 복잡도를 가지고 있어 이 삽입문이 for 반복문 안에 들어가 있으므로 O(nlogn)의 시간 복잡도를 갖게 된다.  
그러므로 최종적인 시간복잡도는 O(nlogn)이 된다.  

What I used here is sort and priority_queue. since the sort algorithm uses quick sort in STL, it has a time complexity of O (nlogn). priority_queue has a time complexity of O (logn) when inserting data based on the heap, so this insert statement is contained within a for loop, so it has a time complexity of O (nlogn).  
Therefore, the final time complexity is O (nlogn).  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/top-k-frequent-elements/
