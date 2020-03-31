# 279. Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n. 

**Example1:**   
```
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
```

**Example2:**   

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

## trial1
### Intuition
```
Dynamic programming을 사용하여 결과 값을 추출하였다.
1.  n보다 작은 값중에 square에 해당하는 값들은 memo라는 합의 개수를 저장해놓는 vector에 1로 초기화를 시킨다.
2.  존재하는 square에 대한 vector을 하나 만들어 perfect square을 넣는다.
3.  다시 2부터 n까지 모든 값들에 대하여 memoization을 진행한다. square인 값을 뺀 숫자의 count에 1(square을 만들수 있는 숫자의 개수)을 더한 값과 현재 저장된 값중 작은값으로 i번째 숫자의 count를 업데이트 한다.

The result was extracted using dynamic programming.
1. Among the values ​​smaller than n, counts of square values ​​are initialized to 1 in a vector that stores the number of sums called "memo".
2. Create a vector for the existing square called as "ps" and insert the perfect square in it.
3. Again, memoization is executed for all values ​​from 2 to n. The count of the i-th digit is updated by adding 1 (the number of perfect square that can make a perfact square) to the count of number minus the square value.
```
### Codes  
```cpp
class Solution {
public:
	int numSquares(int n) {
		vector<int> memo(n+1, n);
		vector<int> ps;
		double tmp = 0;
		int j = 0,i;
		for (i = 1; i <= n; i++) {
			tmp = sqrt(i);
			if ((tmp - floor(tmp)) == 0) {//square이라면
				memo[i] = 1;
				ps.push_back(i);//perfect square 목록에 넣기
			}
		}
        int val=0;
		for (i = 2; i <= n; i++) {
            tmp = sqrt(i);
			if ((tmp - floor(tmp)) != 0) {//square가 아닌경우에만 진행
                for (j = 0;j < ps.size() && ps[j]<i; j++) {//모든 square에 대해서 구함
                    val=(memo[i - ps[j]] + 1);
                    memo[i] = (val > memo[i] ? memo[i] : val);
                }
            }
		}
		return memo[n];
	}
};
```

## trial2 (다른 코드를 참고하여 작성함)
### Intuition
```
Dynamic programming을 사용하여 결과 값을 추출하였다. (개념은 위와 같지만 static과 square의 vector을 없애어 더 좋은 방법을 사용)
1.  memo라는 vector에 0번째 값을 초기화 시킨다.
2.  memo의 사이즈가 n+1이라는 것은 n번째 값까지 구한 square들의 합의 개수를 모두 구한 상태이므로 memo의 사이즈가 n번째까지 진행한다.
3.  for 반복문 안에서는 현재 memo의 사이즈안에 존재하는 square들에 대하여 반복문을 실행시켜 준것이다.
4.  현재 i값에서 square을 뺀 인덱스의 memo 값 +1이 i번째 square들의 합 count가 될 후보인데 이중 가장 작은 값으로 업데이트를 해준다.


The result was extracted using dynamic programming. (The concept is the same as above, but use a better method by eliminating static and square vectors)
1. Initialize the 0th value in the vector called memo.
2. Since the memo size is n + 1, the number of sums of squares obtained up to the nth value is all obtained, so the memo size proceeds to the nth size.
3. Inside the for loop, it executes the loop for squares existing in the size of the memo.
4. The memo value of the index minus square from the current i value +1 is a candidate to be the sum count of the i-th squares, which is updated to the smallest value.
```
### Codes  
```cpp
class Solution {
public:
	int numSquares(int n) {
		static vector<int> memo(1, 0);//0번째 초기화
		int i, mi;
		while (memo.size() <= n) {//memo에 n만큼의 값을 모두 계산 했을 때
			i = memo.size();
			mi = n;
			for (int j = 1; j*j <= i; j++) {//현재까지 만들어진 숫자보다 작은 모든 square에 대해서 진행하기
				mi = min(mi, memo[i - j * j] + 1);//현재값에서 square값을 뺀 인덱스의 count에 1더한값과 현재 count 값과 비교하여 작은값 넣어주기
			}
			memo.push_back(mi);//모든 square에 대해서 값을 구해주면 memo에 삽입(memo 안에는 가장 작은 count들이 나열되게 된다.)
		}
		return memo[n];
	}
};
```

### Results (Performance)  
**Runtime:**  152 ms(static을 사용하지 않은경우) 4 ms  O(kn)이고 k는 n숫자 안에 존재하는 perfect square의 개수
**Memory Usage:** 	13.2 MB(static을 사용하지 않은 경우) 	6.5 MB

<p align="center"> 
<img src="./capture2.JPG">
</p>

### Discussion
이문제를 통해서 static을 사용했을때와 사용하지 않았을때 성능차이를 보여준다는 것을 알게 되었다.  
그리고 같은 dp라도 성능을 최적화 하는 것이 중요하다는 것을 알게 되었다.

Through this problem, I found that it shows the performance difference when static is used and not used.
And I found it important to optimize performance even for the same dp.  

### 문제 URL (LeetCode)  
https://leetcode.com/problems/perfect-squares/