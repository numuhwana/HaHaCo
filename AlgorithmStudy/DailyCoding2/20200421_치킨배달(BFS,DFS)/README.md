# 치킨 배달 

크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.  

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.  

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.  

예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.  

0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
0은 빈 칸, 1은 집, 2는 치킨집이다.    

(2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.  

(5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.  

이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.  

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.  

**입력**
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

**출력**
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.

**Example1:**   
```
5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2

10
```

**Example2:**   
```
5 1
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0

11
```

**Example3:**   
```
5 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1

32
```

## trial1
### Intuition
```
dfs를 이용하여 문제를 풀었다.   
choose라는 함수에서 남아있어야 하는 치킨집의 개수만큼 만족할때에는 모든 집과 모든 치킨집에 대한 거리를 계산해주어 minimum 값을 구하게 된다.  
choose 함수는 vector을 이용하여 stack 처럼 사용하였고 밑의 그림과 같이 순서가 이루어진다.
```
![pic.JPEG](https://github.com/numuhwana/SamsungCoding/blob/master/20200421_%EC%B9%98%ED%82%A8%EB%B0%B0%EB%8B%AC/pic.jpg)

### Codes  
```cpp
struct chicken {
	int x, y;
};
struct house {
	int x, y,len=2601;
};
vector<chicken> c;
vector<house> h;
vector<chicken> q;
void findway(vector<chicken> qq, vector<house> hh) {
	chicken k;
	int tmplen,localmin=0;
	while (!qq.empty()) {//모든 치킨집에 대하여
		k = qq.back();
		qq.pop_back();
		for (int i = 0; i < hh.size(); i++) {//모든 집에 대하여
			tmplen = abs(k.x - hh[i].x) + abs(k.y - hh[i].y);
			if (hh[i].len > tmplen) {
				hh[i].len = tmplen;//거리가 더 짧으면 업데이트
			}
		}
	}
	for (int i = 0; i < hh.size(); i++) {//모든 집에 대하여
		localmin += hh[i].len;
	}
	len = (localmin < len ? localmax : len);
}
void choose(int cur) {
	if (q.size() == m) {
		findway(q,h);
	}
	else {
		for (int i = cur; i < c.size(); i++) {
				q.push_back(c[i]);
				choose(i+1);
				q.pop_back();
		}
	}
}
```
### Results (Performance)  
**Runtime:**  4 ms O() (t=초수, r=row, c=column)  
**Memory Usage:** 	1996 MB  


<p align="center"> 
<img src="./capture.JPG">
</p>


### 문제 URL ((백준) )  
https://www.acmicpc.net/problem/17144