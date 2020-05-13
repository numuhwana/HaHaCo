# 5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

**Example1:**   
```
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer. 
```

**Example2:**   
```
Input: "cbbd"
Output: "bb"
```

## trial1
### Intuition
```
1.  3중 for문을 이용하여 구현하였다.
2.  첫번째 for문은 주어진 string의 길이에서 palindrome이 될 수 있는 최대의 길이를 뺀만큼까지의 모든 인덱스에 대하여 palindrome을 찾기 위한 반복문이다.
3.  두번째 for문은 현재 인덱스에 대하여 될수 있는 최대의 palindrome만큼 characters를 추가해나가고 palindrome인지를 확인하기 위한 for문이다.
4.  마지막 for문은 현재 만들어진 string이 palindrome인지를 확인하는 for문이다.
5.  마지막 for문을 빠져나왔을때에는 최대 길이의 palindrome이 만들어졌는지를 판단하여 현재 최대의 palindrome의 정보를 업데이트한다.

1. It was implemented using triple for statement.
2. The first for statement is a loop to find a palindrome for all indices up to the given string length minus the current maximum length of palindrome which can be updated.
3. The second for statement is to add characters as many as the maximum possible palindrome for the current index and to check if it is a palindrome.
4. The last for statement is a loop that checks whether the currently created string is a palindrome.
5. When exiting the last for statement, it determines whether the maximum length of the palindrome has been created and updates the current maximum palindrome.
```
### Codes  
```cpp
class Solution {
public:
	int mx = 0;
	string ans = "";
	bool update = true;
	string sub = "";
	string longestPalindrome(string s) {
		for (int i = 0; i < s.size()-mx; i++) {
			sub="";
			for (int j = i; j < s.size(); j++) {
				sub += s[j];
				if (mx < sub.size()) {
					update = true;
					for (int j = 0; j < sub.size() / 2; j++) {
						if (sub[j] != sub[sub.size() - j - 1]) {
							update = false;
							break;
						}
					}
					if (update) {
						ans = sub;
						mx = sub.size();
					}
				}
			}
		}
		return ans;
	}
};
```

### Results (Performance)  
**Runtime:** 264 ms   
**Memory Usage:** 8.2 MB   

<p align="center"> 
<img src="./capture.JPG">
</p>

### Discussion
내가 푼 방식은 speed가 O(n^3)이므로 느린편에 속한다. 그러므로 좀 더 나은 방법을 찾아서 풀어보는 것이 필요한 것으로 보인다.

The method I solved is on the slow side because the speed is O (n ^ 3). Therefore, it seems necessary to find a better way to solve it.

### 문제 URL (LeetCode)  
https://leetcode.com/problems/longest-palindromic-substring/
