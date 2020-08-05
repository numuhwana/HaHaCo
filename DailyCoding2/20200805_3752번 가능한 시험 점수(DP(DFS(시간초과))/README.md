# 가능한 시험 점수
문제 사이트 참조
**Example1:**   
```
2 ->test case
3 -> 문제수
2 3 5
10 ->문제수
1 1 1 1 1 1 1 1 1 1

#1 7
#2 11
```

## trial1
### Intuition
```
처음에는 dfs로 풀었다 
생각해보니까 문제수가 100개와 같이 숫자가 큰 경우에는 dfs와 같이 recursion으로 풀게되면 당연히 
시간초과가 나게 된다.

dfs로 풀때는 문제마다 0인경우 혹은 배점인 경우 두가지로 나누어서 recursion을 돌려주어야한다.
```

### Codes  
```cpp
void function(vector<int> &v,int& n,vector<int>& v2,int cur) {
	if (v2.size() == n) {
		int sum = 0;
		for (int i : v2) {
			sum += i;
		}
		if (m.find(sum) == m.end()) {
			m[sum] = true;
		}
	}
	else {
		if (cur == v.size()) return;
		v2.push_back(0);
		function(v, n, v2, cur + 1);
		v2.pop_back();
		v2.push_back(v[cur]);
		function(v, n, v2, cur + 1);
		v2.pop_back();

	}
}
```

## trial2
### Intuition
```
두번째 trial에서는 dp를 사용하여 해결한 문제이다. 
규칙을 찾아보면
2 3 5 배점이 이러한 문제들이 있으면 전부 틀린경우에 해당하는 0점은 답에 속하게 된다.
그러므로 밑의 코드에서 v2가 배점들의 조합의 합의 집합이라고 하면 0은 무조건 들어가게 된다.
v2가 0일때부터 시작해서 각 문제에 대해서 반복문을 돌리는데 이때 나올수 있는 배점은 
배점이 2점인 경우 현재 v2에 들어있는 값 0에 2점을 더하여 2 0 0 이렇게 받는 경우에 대한 점수가 나온다.
아직 이점수에 대해서는 v2에 넣은적이 없으므로 push_back 하게 되고 visit는 true로 만들어준다.
여기서 중요한 점은 v2의 사이즈를 미리 len에 받은 다음에 이중 for문을 돌려주어야 한다.
v2의 사이즈는 변하기 때문에 안그러면 무한루프를 돌게 되기 때문이다.

그리고 현재 v2에 0 2 가 들어있는 상황에서 3에 대해서 반복문을 돌려주게 되면
0에 3을 더한 값과 2에 3을 더한 값이 v2에 들어가게 된다.
결과적으로 0 2 3 5가 된다.

v2가 0 2 3 5인 상황에서 5에 대해서 반복문을 돌려주게 되면
0에 5를 더한값 5(이미 v2에 존재하므로 패스)
2에 5를 더한값 7
3에 5를 더한값 8
5에 5를 더한값 10
이 되므로 이 숫자들이 v2에 추가된다.
최종적으로 0 2 3 5 7 8 10이 되므로 사이즈는 7을 반환한다.

이 예시와 같이 각 문제의 배점에 대하여 지금까지 나온 배점들의 합과 더해주게 되면 모든 경우의 수의 배점을 찾을수 있게 된다.

```

### Codes  
```cpp
int function(vector<int> &v,int& n,int total) {
	vector<bool> visit(total + 1, false);
	vector<int> v2;
	visit[0] = true;
	v2.push_back(0);
	for (int i = 0; i < v.size(); i++) {
		int len = v2.size();
		for (int j = 0; j < len; j++) {
			int tmp = v2[j] + v[i];
			if (!visit[tmp]) {//visit을 안했을 경우에만 더하기
				v2.push_back(tmp);
				visit[tmp] = true;
			}
		}
	}
	return v2.size();
}
```

### Results (Performance)    
**Runtime:**  C++의 경우 1초 이내 O(문제수(n)x(total/2)) 이므로 O(nxtotal)이다.
**Memory Usage:** 	힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내    


<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (SW expert Academy)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&categoryId=AWHPkqBqAEsDFAUn&categoryType=CODE&&&&&&