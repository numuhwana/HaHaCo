#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int arr[201][201] = { 0, };
int mina[201][201] = { 0, };
bool visit[201][201][31] = { 0, };
int k, w, h,stest=-1;
queue<pair<pair<int, int>, pair<int, int>>> q;//1-1: 남은 k수, 1-2: 현재 걸음수, 2-1:x 2-2:y
int xx[4] = { 0,1,-1,0 }, yy[4] = { 1,0,0,-1 };
//int hx[8] = { 1,2,1,2,-1,-2,-1,-2 }, hy[8] = { -2,-1,2,1,2,1,-2,-1 };
int hx[8] = { 1,1,2,2,-2,-2 ,-1,-1  }, hy[8] = { -2,2,-1,1,-1,1,-2,2 };
int visitall() {
	pair<pair<int,int>, pair<int, int>> cur;
	int x, y,kk,walk,nx,ny;
	while (!q.empty()) {
		cur = q.front();
		kk = cur.first.first;
		walk = cur.first.second;
		x = cur.second.first;
		y = cur.second.second;
		q.pop();
		if (x == w-1 && y == h-1) {//가장 먼저 들어온애가 최단거리..?
			stest = walk;
			break;
		}
		
		if (kk >= 1) {
			for (int i = 0; i < 8; i++) {
				nx = x + hx[i];
				ny = y + hy[i];
				if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
					if (arr[ny][nx] != 1 && !visit[ny][nx][kk - 1]) {
						q.push(make_pair(make_pair(kk - 1, walk + 1), make_pair(nx, ny)));
						visit[ny][nx][kk - 1] = true;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			nx = x + xx[i];
			ny = y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
				if (arr[ny][nx] != 1 && !visit[ny][nx][kk]) {
					q.push(make_pair(make_pair(kk, walk + 1), make_pair(nx, ny)));
					visit[ny][nx][kk] = true;
				}
			}
		}
	}
	return stest;
}
int main() {
	freopen("test.txt", "r", stdin);
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin>>arr[i][j];
		}
	}
	q.push(make_pair(make_pair(k,0),make_pair(0, 0)));
	cout<<visitall();
	return 0;
}