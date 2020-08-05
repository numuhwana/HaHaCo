# 문자열
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.

두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

**Example1:**   
```
adaabc aababbc

2
```

**Example2:**   
```
jimae
najimjima

2
```

## trial1
### Intuition
```
A문자열이 B 문자열에 어떤 인덱스부터 가장 비슷한지를 찾으면 된다.

그렇기 때문에 0부터 B문자열에서 A문자열의 차이만큼까지 반복문을 돌려서 B문자열의 인덱스 0부터 차이만큼까지 A와 문자열의
같은 정도를 비교하여 cnt를 세어주었다.
```

### Codes  
```cpp
int main() {
	//freopen("문자열.txt", "r", stdin);
	string a, b;
	cin >> a;
	cin >> b;
	int cnt = 0;
	int mcnt = 0;
	int dif = b.size() - a.size();
	for (int i = 0; i <= dif; i++) {
		cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == b[i+j]) {//같다면
				cnt++;
			}
		}
		mcnt = max(mcnt, cnt);
	}
	cout << b.size()-mcnt-dif;
}
```

### Results (Performance)    
**Runtime:**  0 ms   
**Memory Usage:** 	1984 kB    


<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL (백준)  
https://www.acmicpc.net/problem/1120