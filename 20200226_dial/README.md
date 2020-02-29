# 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.  
<p align="center"> 
<img src="./telphone.png">
</p>
<center><img src="./telphone.png"></center>  
![telphone](./telphone.png) 
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.  

2부터 9까지의 dial을 눌러 만들수 있는 문자열의 조합을 구하는 문제  
Input 값이 숫자로 주어지면 숫자에 따른 만들수 있는 모든 문자열의 vector을 반환한다.   

### example  
Input: "23"  
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].  

## trial1
## Intuition
알고리즘 설명
1.주어진 digits 변수가 값이 없는경우에는 아무것도 반환하지 않음  
2.주어진 digits 변수에 값이 있는 경우 choose라는 함수를 호출  
3.choose 함수는 combination을 재귀적으로 호출하기 위한 함수이다.  
주어진 digits의 각 글자마다 choose 함수를 호출하여 문자를 고르게 된다.  
4.cur은 digits의 index라고 할 수 있고 이 cur 변수가 digits의 size 즉 모든 digits에 대한 choose 함수가 호출되면 
반환해야할 vector에 삽입한다.  
5.cur이 아직 digits의 끝까지 오지 않았다면 digits 문자열의 cur번째 숫자와 관련된 characters(2인경우 a,b,c)들을 한번씩 골라주어야 하므로 for문을
이용해서 한 character씩 골라주게 된다.  
6.character을 골랐다면 digits 의 다음 위치에 대하여 character을 골라주어야 하므로 choose 함수를 호출하면서 cur 변수에 1을 더해서 이동한다.  
7.choose 함수에 들어갈때에는 tmp 문자열에 현재 선택된 character이 추가된 상태로 진행되어야 하므로 tmp = tmp + let[whtchar][i] 로 추가해준다.  
8.choose 함수가 끝나게 되면 현재 선택된 character은 다시 지워지고 현재 dial의 다른 character이 선택되어야 하므로 백업을 해준다.  

## Codes  
```cpp
class Solution {
public:
	void print(string a) {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
		}cout << endl;
	}
	vector<vector<string>> let = {
		{""},
		{""},
		{"a","b","c"},//2
		{ "d","e","f" },//3
		{ "g","h","i" },//4
		{ "j","k","l" },//5
		{ "m","n","o" },//6
		{ "p","q","r","s" },//7
		{ "t","u","v" },//8
		{ "w","x","y","z" }//9
	};
	void choose(string digits,int cur,vector<string> &arr,string tmp) {
		if (cur == digits.size()) {//현재 가르키는 digits[cur]이 이미 범위 밖일때
			arr.push_back(tmp);
			//print(tmp);
		}
		else {//아닌경우 더 진행하기
			int whtchar = digits[cur] - '0';
			for (int i = 0; i < let[whtchar].size(); i++) {
				string backup = tmp;
				tmp = tmp + let[whtchar][i];
				choose(digits, cur + 1, arr, tmp);
				tmp = backup;
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		string tmp = "";
		vector<string> arr;
		if (digits == "") {
			return arr;
		}
		else {
			choose(digits, 0, arr, tmp);
			return arr;
		}
	}
};
```

## Results (Performance)  
Runtime: 4 ms  
Memory Usage: 8.7 MB  


## 문제 URL (LeetCode)  
https://leetcode.com/problems/letter-combinations-of-a-phone-number/  
