# 9280. 진용이네 주차타워
진용이네 주차공간 (문제에 대한 내용은 저작권 문제로 사이트를 참고)

**Input:**   
```
2			// 테스트 케이스 개수 TC = 2
3 4			// 첫 번째 테스트 케이스 n = 3,  m = 4
2			// 단위 무게당 요금 R_i = {2, 3, 5}
3
5
2			// 차량의 무게 W_i = {2, 1, 3, 8}
1
3
8
3		// i = 3 인 차량이 들어옴	
2		// i = 2 인 차량이 들어옴
-3		// i = 3 인 차량이 나감
1		// i = 1 인 차량이 들어옴
4		// i = 4 인 차량이 들어옴
-4		// i = 4 인 차량이 나감
-2		// i = 2 인 차량이 나감
-1		// i = 1 인 차량이 나감
2 4		// 두 번째 테스트 케이스 n = 2,  m = 4
5		// 단위 무게당 요금 R_i = {5, 2}
2
100		// 차량의 무게 W_i = {100, 500, 1000, 2000}
500
1000
2000
3		// i = 3 인 차량이 들어옴
1		// i = 1 인 차량이 들어옴
2		// i = 2 인 차량이 들어옴
4		// i = 4 인 차량이 들어옴
-1		// i = 1 인 차량이 나감
-3		// i = 3 인 차량이 나감
-2		// i = 2 인 차량이 나감
-4		// i = 4 인 차량이 나감
```

**Input:**   
```
#1 53
#2 16200	// 첫 번째 테스트 케이스 결과
// 두 번째 테스트 케이스 결과
```
## trial1
### Intuition
```
1. 주차 공간에 대한 index를 heap(priority_queue)를 이용해서 제일 작은 순으로 뽑아주고 다시 넣어주는 방식으로 진행
2. 주차 공간이 없을 경우에는 waiting list에 대한 wait queue를 만들어 주었다.
3. 차량이 나가는 경우와 들어오는 경우에 대해서 logic을 다르게 작성한다. 
```
### Codes  
```cpp
int main() {
int T,N,M;
cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cin>>M;
		int total = 0;
		vector<int> W;
		priority_queue<int,vector<int>,greater<int>> Ridx;
		vector<int> R;
		queue<int> wait;
		vector<int> visit(M,0);
		for (int j = 0; j < N; j++) {
			int r=0;
			cin >> r;
			R.push_back(r);
			Ridx.push(j);
		}
		for (int j = 0; j < M; j++) {
			int w = 0;
			cin >> w;
			W.push_back(w);
		}
		for (int j = 0; j < W.size() * 2; j++) {
			int cur = 0;
			cin >> cur;//cur을 받고 cur에 대한 일을 함
			if (cur < 0) {//차가 빠짐
				cur *= (-1);
				Ridx.push(visit[cur - 1]);//다시 주차장이 비게됨
				if (!wait.empty()) {//웨이팅이 있으면 들여보네주기
					cur = wait.front();
					wait.pop();
					visit[cur - 1] = Ridx.top();
					total += (R[Ridx.top()]*W[cur - 1]);//요금
					Ridx.pop();
				}
			}
			else {//차가 들어옴
				if (!Ridx.empty()) {//주차장이 꽉찬상태가 아니라면
					if (!wait.empty()) {//웨이팅이 있으면 먼저 들여보네주기
						wait.push(cur);
						cur = wait.front();
						wait.pop();
					}
					visit[cur - 1] = Ridx.top();
					total += (R[Ridx.top()]*W[cur - 1]);//요금
					Ridx.pop();
				}
				else {
					wait.push(cur);//waiting 리스트에 추가
				}
			}
		}
		cout << "#" << i + 1 << " ";
		cout << total << endl;
	}
return 0;
}
```

### Results (Performance)  
**Runtime:** 32 ms   
**Memory Usage:**  12,696 kb  

### Discussion
처음에 문제를 잘 못 이해하여 비용이 낮은 주차공간을 우선순위로 주차하는 것이라 생각하여 heap변수를 잘못 사용하여 문제를 잘 못 풀었었다. 이전에 잘 못 짠 코드에서 다시 수정하면서 vector을 하나 더 추가하여 코드가 좀더 복잡하게 짜여진 것 같았다.

### 문제 URL (SW expert academy)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW9j74FacD0DFAUY
