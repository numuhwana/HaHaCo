# 활주로건설

문제정보 : 사이트 참조  
 

**입력**  
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,  

그 다음 줄부터 T 개의 테스트 케이스가 주어진다.  

각 테스트 케이스의 첫 번째 줄에는 지도의 한 변의 크기인 N 과 경사로의 길이 X 가 주어진다.  

다음 N 개의 줄에는 N * N 크기의 지형 정보가 주어진다.        

**출력**  
테스트 케이스 개수만큼 T 개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.  

각 줄은 "#t" 로 시작하고 공백을 하나 둔 다음 정답을 출력한다. ( t 는 1 부터 시작하는 테스트 케이스의 번호이다. )  

정답은 활주로를 건설할 수 있는 경우의 수이다.   

**Example1:**   
```

10

6 2

3 3 3 2 1 1

3 3 3 2 2 1

3 3 3 3 3 2

2 2 3 2 2 2

2 2 3 2 2 2

2 2 2 2 2 2

6 4

3 2 2 2 1 2

3 2 2 2 1 2

3 3 3 3 2 2

3 3 3 3 2 2

3 2 2 2 2 2

3 2 2 2 2 2


#1 7

#2 4

#3 11
```

## trial1
### Intuition
```
경사로를 놓는 조건에 따라서 처음 시작할때는 cur은 1부터 시작한다. (cur은 현재블록과 숫자가 같은 블록의 개수이다.)
만약에 이전 블록과 같은 블록이라면 cur에 1을 증가시킨다.
만약에 이전 블록보다 큰 블록이라면 cur은 x만큼의 숫자를 만족해야만 경사로를 세울 수 있다.
만약에 이전 블록보다 작은경우에는 cur을 -(x-1)로 선언하고 같은 숫자의 블록이 x-1번 나와야지만 내리막길 경사로가 완성이 될 수 있다.
이런 경우들을 만족하게 되도록 코드를 작성하면 된다.
```

### Codes  
```cpp
int T = 0,n,x,cnt=0;
int arr[21][21] = { 0, };
int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	int cur = 0,prev=0;
	for (int t = 0; t < T; t++) {
		cin >> n >> x;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			cur = 0;
			prev = arr[i][0];
			for (int j = 0; j < n; j++) {
				if (prev == arr[i][j]) cur++;
				else if (prev+1 == arr[i][j]) {//전값보다 현재값이 큰경우
					if (cur >= x) {//이전에 2개이상을 이미 쌓아와야지 만족
						cur = 1;//1로 초기화
					}
					else {
						cur = -1;
						break;//이미 만족을 못함
					}
				}
				else if(prev-1==arr[i][j]){//현재값이 더 작은경우
					if (cur < 0) { break; }
					cur = -(x - 1);//-1로 초기화
				}
				else {
					cur = -1;
					break;
				}
				prev = arr[i][j];
			}
			if (cur >= 0) cnt++;//0이상이어야만 경사로 가능
		}
		for (int i = 0; i <n; i++) {
			cur = 0;
			prev = arr[0][i];
			for (int j = 0; j < n; j++) {
				if (prev == arr[j][i]) cur++;
				else if (prev+1 == arr[j][i]) {//전값보다 현재값이 큰경우
					if (cur >= x) {//이전에 2개이상을 이미 쌓아와야지 만족
						cur = 1;//1로 초기화
					}
					else {
						cur = -1;
						break;//이미 만족을 못함
					}
				}
				else if(prev-1==arr[j][i]) {//현재값이 더 작은경우
					if (cur < 0) { break; }
					cur = -(x-1);//-1로 초기화
				}
				else {
					cur = -1;
					break;
				}
				prev = arr[j][i];
			}
			if (cur >= 0) cnt++;//0이상이어야만 경사로 가능
		}
		cout << "#" << t + 1 << " " << cnt<<endl;

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


### 문제 URL (SW expert)  
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH&categoryId=AWIeW7FakkUDFAVH&categoryType=CODE&&&&&&