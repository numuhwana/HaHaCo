# 394. Decode String
Given an encoded string, return its decoded string.  

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.  
Note that k is guaranteed to be a positive integer.  

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.  

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].  

숫자[알파벳] -> 알파벳을 숫자만큼 반복  
위와 같이 string을 decode하여 표현한다.   

**Examples:** 
```
s = "3[a]2[bc]", return "aaabcbc".  
s = "3[a2[c]]", return "accaccacc".  
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".  
```

## trial1
### Intuition
```
1.  isdigit을 이용해서 숫자라면 '[' 가 나오기 전까지 숫자 string에 이어붙여서 나중에 숫자로 convert 해준 후에 nums vector에 넣어준다.  
2. '['가 s[i]에 나오게 된다면 string을 새롭게 생성해서 vector<int> sub에 push 해준다. (이것은 []안에 다른 []이 있는 경우를 처리해주기 위함)  
3. ']'를 만나게 된다면 가장 마지막에 나온 '['와 짝궁이 되고 가장 마지막에 들어온 nums가 이 브라켓의 반복 횟수가 된다.  
위의 방법은 vector 즉 스택을 이용하여 구현한 방법이다.
```
### Codes  
```cpp
void decode(vector<int>& nums, string &sub) {
	string str;
	int num = nums.back();//현재 숫자의 가장 마지막꺼를 넣어준다.(이말은 가장 안쪽에 있는 괄호의 숫자를 뜻한다)
	nums.pop_back();
	string tmp = sub;
	for (int z = 1; z < num; z++) {
		sub += tmp;
	}
}
string solution(string s) {
	if (s.size() > 0) {
		vector<int> nums;
		vector<string> sub;
		sub.push_back("");//초기화
		string num;
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {//숫자인경우에는 숫자 string에 우선 넣어준다.
				num += s[i];
			}
			else if (s[i] == '[') {//왼쪽 괄호 나온경우
				string ss = "";
				nums.push_back(atoi(num.c_str()));//숫자를 stack 구조인 nums vector에 넣는다.
				num = "";
				sub.push_back(ss);//sub string 벡터에 새로운 string을 추가한다.
			}
			else if (s[i] == ']') {//오른쪽 괄호면 하나씩 추가
				decode(nums,sub.back());//decode를 실행한다. =반복해준다. 반복된 string을 sub.back()에 적용
				string ss = sub.back();//반복한 string을 ss에 넣어준다.
				if (sub.size() > 1) {//	sub 괄호가 안에 또 존재하는 경우
					sub.pop_back();//가장 안에있는것부터 pop해준다
					sub.back() += ss;//그다음 안에 있는 것 뒤에 붙여준다.
				}
			}
			else {
				sub.back() += s[i];//괄호가 끝나기 전까지 가장 마지막에 나온 string에 더해준다.
			}
		}
		return sub.back();
	}
	else {
		return "";
	}
}
```

### Results (Performance)  
**Runtime:** 0 ms  
**Memory Usage:** 8 MB

### Discussion
사실 코드를 다 작성하고나니 left와 right에 대한 vector은 굳이 필요가 없다는 것을 느꼈다.


### 문제 URL (LeetCode)  
https://leetcode.com/problems/decode-string/ 
