# 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.  


## Example1

```
For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

## trial1
### Intuition
```
unordered_map을 사용하여 각 letters들에 대해서 r에 존재한 letters들은 1씩 증가시켜주고 mag에 대해서는 --를 진행합니다.
만약에 이 map 안에 값들이 0보다 큰값이 있으면 r값이 mag에 들어있지 않다는 뜻입니다.


Using unordered_map, for each letters, the letters in r are incremented by 1, and for mag, proceed with-.
If the values ​​in this map are greater than 0, it means that the value of r is not in mag.
```
### Codes  
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }
    void dfs(vector<string>& res,string cur, int lt, int rt) {
        if (lt > rt) return;
        if (lt == 0 && rt == 0) {
            res.push_back(cur);
            return;
        }
        if (lt > 0) {
            cur += "(";
            dfs(res, cur, lt - 1, rt);
            cur.pop_back();
        }
        if (rt > 0) {
            cur += ")";
            dfs(res, cur, lt, rt - 1);
            cur.pop_back();
        }
    }
};
```

### Results (Performance)  
**Runtime:**  768 ms  
**Memory Usage:** 	16.2 MB  


<p align="center"> 
<img src="./capture.JPG">
</p>



### 문제 URL (LeetCode)  
https://leetcode.com/problems/generate-parentheses/