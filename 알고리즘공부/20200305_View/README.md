# 1206. [S/W 문제해결 기본] 1일차 - View
강변에 빌딩들이 옆으로 빽빽하게 밀집한 지역이 있다. ...(문제에 대한 내용은 저작권 문제로 사이트를 참고)

**Input:**  
[입력]

입력 파일의 첫 번째 줄에는 테스트케이스의 길이가 주어진다. 그 바로 다음 줄에 테스트 케이스가 주어진다.  

총 10개의 테스트케이스가 주어진다.     
```
100
0 0 225 214 82 73 241 233 179 219 135 62 36 13 6 71 179 77 67 139 31 90 9 37 ...
1000
0 0 225 214 82 73 241 233 179 219 135 62 36 13 6 71 179 77 67 139 31 90 9 37 ...
...

```

**ouput:**  
[출력]

조망권이 확보된 세대의 수를 출력한다.     
```
#1 691
#2 9092
...
```
## trial1
### Intuition
```
1. Left와 Right의 가장 큰 값을 현재 index의 높이와 비교해서 그에 대한 차가 조망권을 가지게 되는 건물 층수이다.
```
### Codes  
```cpp
int main() {
	//freopen("input.txt", "r", stdin);
	for (int z = 0; z < 10; z++) {
		int cnt=0;
		int N = 0;
		cin >> N;
		vector<int> arr(N, 0);//원래 사이즈 앞뒤로 두개 추가해야함
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		int L = 0, R = 0;
		for (int i = 2; i < arr.size() - 2; i++) {
			L = max(arr[i - 2], arr[i - 1]);
			R = max(arr[i + 1], arr[i + 2]);
			int mx = max(L, R);
			if (arr[i] > mx) {
				cnt += arr[i] - mx;
			}
		}
		cout << "#" << z + 1 << " " << cnt << endl;
	}
	return 0;
}
```

### Results (Performance)  
**Runtime:** 11 ms   
**Memory Usage:**  12,680 kb 


### 문제 URL (SW expert academy)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh
