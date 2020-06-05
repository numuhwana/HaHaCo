#include <iostream>
#include <queue>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
int w, h,nx,ny;
char arr[51][51] = { 0, };
static int xx[4] = { 0,0,1,-1 };
static int yy[4] = { 1,-1,0,0 };
struct land {
	int x, y;
	int len=0;
};
int mx = 0;
queue<land> q;
int findtr(land cur,vector<vector<bool>> visit) {
	queue<land> qq;
	qq.push(cur);
	int localmx = 0;
	visit[cur.y][cur.x] = true;
	land nxl;
	while (!qq.empty()) {
		cur = qq.front();
		qq.pop();
		if (cur.len > localmx) localmx = cur.len;//지금까지의 최대수를 넣기
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h) {//범위 안이라면
				if (!visit[ny][nx] && arr[ny][nx]=='L') {//아직 들르지 않은 땅이라면 q에 넣기
					visit[ny][nx] = true;
					nxl.x = nx;
					nxl.y = ny;
					nxl.len = cur.len+1;
					qq.push(nxl);
				}
			}
		}
	}
	return localmx;
}
int main() {
	//freopen("test.txt", "r",stdin);
	cin >> h >> w;
	land l;
	int localmx = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L') {
				l.x = j;
				l.y = i;
				q.push(l);
			}
		}
	}
	vector<vector<bool>> visit(h, vector<bool>(w, 0));
	while (!q.empty()) {
		l = q.front();
		q.pop();
		localmx=findtr(l,visit);
		if (localmx > mx) mx = localmx;//최소 거리중 가장 먼거리라면?
	}
	cout << mx;

	return 0;
}