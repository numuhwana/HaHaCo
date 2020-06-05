#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
//#pragma warning (disable:4996)
using namespace std;
int n, v;
int arr[51][51] = { 0, };
int sec=2501;
int all = 0;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
struct vi {
	int x, y;
	int min=0;
};
vector<vi> virus;
deque<vi> d;
void spread(deque<vi> dd) {
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	vi cur;
	int nx, ny;
	int localmx = 0;
	int tmp = all;//방문해야하는 모든 영역 개수
	while (!dd.empty()) {
		cur = dd.front();
		dd.pop_front();
		if (!visit[cur.y][cur.x]) tmp--;
		
		visit[cur.y][cur.x] = true;
		if (localmx > sec) {//이미 시간 넘어가면 버려
			return;
		}
		if (arr[cur.y][cur.x] != 2) {//바이러스가 아닐때만 현재 시간을 재준다.
			localmx = max(cur.min, localmx);
		}
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!visit[ny][nx] && arr[ny][nx]!=1) {//벽이 아니고 visit하지 않은경우
					tmp--;
					visit[ny][nx] = true;
					vi nw;
					nw.x = nx;
					nw.y = ny;
					nw.min = cur.min + 1;
					dd.push_back(nw);
				}
			}
		}
	}
	if (tmp == 0) {
		sec = min(localmx, sec);
	}
}
void choose(int cur) {//조합
	if (d.size() == v) {
		spread(d);
	}
	else {
		for (int i = cur; i < virus.size(); i++) {
			d.push_back(virus[i]);
			choose(i + 1);
			d.pop_back();
		}
	}
}
int main() {
	//freopen("연구소.txt", "r", stdin);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				vi cc;
				cc.x = j;
				cc.y = i;
				virus.push_back(cc);
			}
			if (arr[i][j] != 1) all++;//벽이 아닌경우에만
		}
	}
	choose(0);
	cout << (sec==2501?-1:sec);
	return 0;
}