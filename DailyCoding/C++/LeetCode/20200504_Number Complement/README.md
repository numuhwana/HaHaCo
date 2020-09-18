# Number Complement
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.     


## Example1

```
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

## Example2
```
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

## trial1
### Intuition
```
cnt 값은 significant bit가 어떤 비트수에 있는지 확인하기 위함이고 
not 연산자를 이용해서 예를들어서 101이면 101의 ~인 010을 봅아낸다. int는 4byte이므로 32에서 cnt만큼 오른쪽으로 shift했다가 다시 왼쪽으로 shift를 한다.

The cnt value is to check which bit number the significant bit is in.
Using the not operator, for example, if 101, we see 010, which is 101. Since int is 4 bytes, it shifts right by 32 to cnt, then shifts left again.
```
### Codes  
```cpp
class Solution {
public:
    int findComplement(int num) {
        int cnt = 0;
        int tmp = num;
        while (tmp != 0) {
            cnt++;
            tmp = tmp >>1;
        }
        tmp = num << (32 - cnt);
        tmp = (~tmp)>>(32-cnt);
        return tmp;
    }
};
```

### Results (Performance)  
**Runtime:**  0 ms  
**Memory Usage:** 	10.3 MB  


<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (LeetCode)  
https://leetcode.com/problems/number-complement/