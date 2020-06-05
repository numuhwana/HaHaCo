# 2×n 타일링

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.  

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.  
  

**입력**  
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)         

**출력**  
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.   


**Example1:**   
```
2

2
```

**Example1:**   
```
9

55
```

## trial1
### Intuition
```
피보나치와 비슷한 계산식으로 i-1번째와 i-2번째의 값을 더해주면 현재값이 나온다
그이유는 아래 그림과 같다.
```
<p align="center"> 
<img src="./pic.JPG">
</p>

### Codes  
```cpp
int main() {
	vector<int> v;
	int n = 0;
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	for (int i = 3; i <= n; i++) {
		v.push_back((v[i - 1] + v[i - 2])%10007);
	}
	cout << v[n];
	return 0;
}
```

### Results (Performance)    
**Runtime:**  0 ms   
**Memory Usage:** 	1984 kB    


<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (백준)  
https://www.acmicpc.net/problem/11726