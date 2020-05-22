# 122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.  

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).  

**Note**
You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example1:**   
```
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
```

**Example2:**   
```
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
```

**Example3:**   
```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```


## trial1
### Intuition
```
sum은 전체 이익의 합이고 fst는 buy를 하는 가격이고 sub는 부분 이익이고 snd는 부분적으로 큰 이익으로 팔수 있는 가격이다. 그래서 p배열에서 i번째 값이 buy를 하는 가격보다 크고 현재 가장 큰 이익으로 팔 가격보다 큰경우 snd와 sub를 업데이트한다. 만약에 아니라면 sum에 부분적인 큰 이익을 더하고 fst는 현재 i번째 값을 그리고 sub는 0으로 snd는 -1로 업데이트를 한다.

"sum" is the sum of the total profits, "fst" is the price to buy, "sub" is the partial profit, and "snd" is the price that can be partially sold. So, if the i-th value in the p-array is greater than the price of the buy and is greater than the parial price that gives largest profit, "snd" and "sub" are updated. If not, add a large partial profit to "sum", "fst" updates the current i-th value, "sub" updates to 0, and "snd" updates to -1.
```
### Codes  
```cpp
class Solution {
public:
	int maxProfit(vector<int>& p) {
		int sum = 0, fst = INT_MAX , sub = 0,snd=-1;
		for (int i = 0; i < p.size(); i++) {
			if (fst < p[i] && snd<p[i]) {
					sub = p[i] - fst;
					snd=p[i];
			}
			else {
				sum += sub;
				fst = p[i];
				sub = 0;
				snd = -1;
			}
		}
		if (sub > 0) sum += sub;
		return sum;
	}
};
```

### Results (Performance)  
**Runtime:**  4 ms
**Memory Usage:** 	7.5 MB

<p align="center"> 
<img src="./capture.PNG">
</p>

### 문제 URL (LeetCode)  
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/