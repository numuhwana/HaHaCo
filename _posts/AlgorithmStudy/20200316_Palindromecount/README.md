# 647. Palindromic Substrings
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.    

**Note:**

The input string length won't exceed 1000.

**Example1:**   
```
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```
**Example2:**   
```
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

## trial1
### Intuition
```
1.  Plindrome 문제를 풀기 위해서 seed라는 vector을 사용하여 1개와 2개의 요소를 저장하였다. 이때 2개의 요소는 두 letter이 같은 경우에만 letter의 인덱스 처음과 끝의 숫자를 pair로 만들어서 seed vector에 넣어준다.
2.  이제 vector를 처음부터 vector의 마지막까지 반복문을 실행해준다.
3.  위의 반복문 안에서는 현재 저장된 seed의 각 pair에서 처음인덱스-1의 letter와 마지막인덱스+1의 letter가 같다면 처음인덱스-1와 마지막인덱스+1를 pair로 만들어서 다시 seed vector 안에 push back 해준다.
4.  다음 작업을 진행해서 for문이 끝이 나게 되면 seed의 길이가 반환값이 된다.

1. To solve the Plindrome problem, one and two elements from string were stored using a vector called a seed. At this time, the two elements are paired with the number of the first and last indexes of the letter only when the two letters are the same.
2. Now run the vector from the beginning to the end of the vector.
3. In the above loop, if the letter of the first index-1 and the letter of the last index + 1 are the same in each pair of the currently stored seed, the first index-1 and the last index + 1 are paired and pushed back into the seed vector.
4. When the for statement ends by proceeding to the next operation, the length of the seed becomes the return value.
```
### Codes  
```cpp
class Solution {
public:
	int countSubstrings(string s) {
		vector<pair<int,int>> seed;
		int j = 0;
		int i = 0;
		for (; i < s.size(); i++) {
			seed.push_back(make_pair(i,i));
			if (j != i && s[j]==s[i]) {
				seed.push_back(make_pair(j, i));
			}
			j = i;
		}
		int nf = 0, ns = 0;
		for (i = 0; i < seed.size(); i++) {
			nf = seed[i].first - 1, ns = seed[i].second + 1;
			if (nf >= 0 && ns < s.size() && s[nf]==s[ns]) {
				seed.push_back(make_pair(nf, ns));
			}
		}
		//print(seed, s);
		return seed.size();
	}
};
```

### Results (Performance)  
**Runtime:** 20 ms   
**Memory Usage:** 17.2 MB  

<p align="center"> 
<img src="./capture.JPG">
</p>
위에서 사용한 방법은 palindrome의 개수만큼의 시간이 걸린다.  

The method used above takes as much time as the number of palindromes.  


### 문제 URL (LeetCode)  
https://leetcode.com/problems/palindromic-substrings/