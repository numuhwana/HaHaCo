#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int r, c,t,cnt=0;
queue<pair<int, int>> q;
void print(int arr[51][51]) {
	for (int z = 0; z < r; z++) {
		for (int j = 0; j < c; j++) {
			cout << arr[z][j] << "  ";
		}cout << endl;
	}cout << endl;
}
struct ac {
	int y[2] = { 0, };
};
int a[51][51] = { 0, };
int xxx[4] = { 1,0,-1,0 }, yyy[4] = { 0,1,0,-1 };
void spread(int tmpa[51][51]) {
	pair<int, int> cur;
	int x, y,nx,ny,part,whole;
	while (!q.empty()) {
		cur = q.front();
		y = cur.first, x = cur.second;
		q.pop();
		whole = a[y][x];
		part = whole / 5;
		for (int i = 0; i < 4; i++) {
			nx = x + xxx[i], ny = y + yyy[i];
			if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
				if (a[ny][nx] != -1) {
					tmpa[ny][nx] += part;
					whole -= part;
				}
			}
		}
		tmpa[y][x] += whole;
	}
}
int xx[4] = { 1,0,-1,0 }, yy[2][4] = { {0,-1,0,1},{0,1,0,-1} };
void clean(ac air, int tmpa[51][51]) {
	int x = 0,nx=0,ny=0,y=0,prev,tmp;
	bool wall = false;
	for (int z = 0; z < 2; z++) {//청소기 위아래 모두 실행
		x = 0;
		y = air.y[z];
		prev = 0;
		for (int i = 0; i < 4; i++) {//위아래 방향으로 실행
			wall = false;
			while (!wall) {//바람의 이동 (벽에 부딪힐때까지)
				nx = x + xx[i];
				ny = y + yy[z][i];
				if (nx < 0 || nx >= c || ny < 0 || ny >= r) {//벽에 부딪혔으므로 방향바꿔야함
					wall = true;
				}
				else {
					if (tmpa[ny][nx] == -1) {
						cnt -= prev;//미세먼지 개수 없애기
						wall = true;
					}
					else {
						tmp = prev;
						prev = tmpa[ny][nx];
						tmpa[ny][nx] = tmp;
						x = nx;
						y = ny;
					}
				}
			}
		}
	}
}
int main() {
	//freopen("test.txt", "r",stdin);
	cin >> r >> c >> t;
	ac air;
	int z = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {//ac라면
				air.y[z] = i;
				z++;
			}
			else if(a[i][j]>0){
				cnt += a[i][j];//미세먼지 수 더하기
				q.push(make_pair(i, j));
			}
		}
	}
	int tmpa[51][51] = { 0, };
	for (int i = 0; i < t; i++) {
		tmpa[air.y[0]][0] = -1;
		tmpa[air.y[1]][0] = -1;
		spread(tmpa);
		clean(air,tmpa);
		for (int z = 0; z < r; z++) {
			for (int j = 0; j < c; j++) {
				if (tmpa[z][j] > 0) {
					q.push(make_pair(z, j));
					a[z][j] = tmpa[z][j];
					tmpa[z][j] = 0;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}