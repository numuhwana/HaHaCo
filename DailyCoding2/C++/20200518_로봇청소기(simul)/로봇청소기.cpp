#include <iostream>
#include <vector>
#include <queue>
//#pragma warning (disable:4996)
using namespace std;
struct robo {
	int x, y;
	int d;//0:북 1:동 2:남 3:서
};
int xx[4] = { 0,1,0,-1 };
int yy[4] = { -1,0,1,0 };
int Y, X;
int arr[51][51] = { 0, };
int cnt=0;
robo r;
int start() {
	int nx, ny;
	bool clean;
	int turn;
	while (1) {
		if (arr[r.y][r.x] == 0) {//청소를 안한구간이면
			arr[r.y][r.x] = 2;
			cnt++;
		}
		clean = false;
		int i = (r.d - 1);
		for (int j=0; j<4; j++,i--) {//0->3->2->1->0 왼쪽 방향부터 탐색
			if (i < 0) i = 3;
			nx = r.x + xx[i];
			ny = r.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < X && ny < Y) {//범위 내인경우
				if (arr[ny][nx] != 1 && arr[ny][nx]!=2) {//청소할 수 있는 공간인경우
					clean = true;
					r.y = ny;
					r.x = nx;
					r.d = i;
					break;
				}
			}
		}
		if (!clean) {//청소할수 있는 부분이 없는경우 후진하기
			turn = (r.d - 2 >= 0 ? r.d - 2 : r.d + 2);//2->0, 3->1, 1->3, 0->2
				nx = r.x + xx[turn];
				ny = r.y + yy[turn];
				if (nx >= 0 && ny >= 0 && nx < X && ny < Y) {//범위 밖이 아닌경우
					if (arr[ny][nx] == 1) {
						break;
					}
					else {//갈수 있는 경우 위치만 이동
						r.y = ny;
						r.x = nx;
					}
				}
				else {//범위 밖인경우
					break;
				}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//freopen("로봇청소기.txt", "r", stdin);
	cin >> Y >> X;
	cin >> r.y >> r.x >> r.d;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin>>arr[i][j];
		}
	}
	cout<<start();
}