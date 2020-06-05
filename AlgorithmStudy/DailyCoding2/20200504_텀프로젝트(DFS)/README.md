# 텀 프로젝트

이번 가을학기에 '문제 해결' 강의를 신청한 학생들은 텀 프로젝트를 수행해야 한다. 프로젝트 팀원 수에는 제한이 없다. 심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다. 프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다. (단, 단 한 명만 선택할 수 있다.) 혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.  

학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.  

예를 들어, 한 반에 7명의 학생이 있다고 하자. 학생들을 1번부터 7번으로 표현할 때, 선택의 결과는 다음과 같다.   
 

1	2	3	4	5	6	7
3	1	3	7	3	4	6
위의 결과를 통해 (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.  

주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.  

**입력**  
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다. 각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)        

**출력**  
각 테스트 케이스마다 한 줄에 출력하고, 각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.  

**Example1:**   
```
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8

결과값
3
0
```

## trial1
### Intuition
```
DFS를 사용한 문제로 김유리 친구의 코드를 참고하여 문제를 해결하였다.
시간 제한이 있기 대문에 조금이라도 비효율적으로 코드를 작성하면 시간 초과가 발생하였다.
visit를 한번 업데이트를 하게 되면 더이상 업데이트를 하지 않도록 한다.

find함수에서 dfs를 돌려주게 되는데 만약에 현재 숫자가 가르키는 학생의 숫자에 대한 visit가 false라면 아직
방문하지 않은 상태이므로 계속 dfs를 진행하도록 한다.
하지만 만약에 visit가 true여서 else문으로 들어가게 되면 cycle이 발생하긴 한것이다. 
그러면 cycle이 발생한 다음 node에 대해서 모든 사이클 안에 존재하는 학생들에 대한 count를 세어주게 된다.
(나중에 전체 학생수에서 count를 빼주면 팀이 이루어지지 못한 학생수가 나오게 된다.)

```

### Codes  
```cpp
int T;
int s;
int cnt = 0;
vector<int> arr;
vector<bool> visit;
vector<bool> cycle;
void find(int cur) {
	visit[cur] = true;
	int nxt = arr[cur];
	if (!visit[nxt]) {//방문하지 않은 경우 방문해본다.
		find(nxt);
	}
	else {//cycle이 생긴경우
		if (cycle[nxt] == false) {//새로운 사이클인지 판단
			for (int i = nxt; i != cur; i = arr[i]) {//nxt부터 모든 사이클의 요소들에 대하여 cnt++
				cnt++;
			}
			cnt++;
		}
	}
	cycle[cur] = true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("test.txt", "r", stdin);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> s;
		cnt = 0;
		arr.push_back(0);
		for (int i = 0; i < s; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
			visit.push_back(false);
			cycle.push_back(false);
		}
		visit.push_back(false);
		cycle.push_back(false);
		for (int i = 1; i <= s; i++) {
 			if(!visit[i]) find(i);
		}
		cout << s-cnt << endl;
		arr.clear();
		visit.clear();
		cycle.clear();
	}
	return 0;
}
```

### Results (Performance)    
**Runtime:**  11 ms   
**Memory Usage:** 	12544 MB    


<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (백준)  
https://www.acmicpc.net/problem/9466

참고함: https://github.com/yu-ri-kim/Coding_Yuri/tree/master/%ED%85%80%20%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8