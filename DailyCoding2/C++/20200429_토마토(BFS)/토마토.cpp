#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int w, h;
struct tom {
	int x=0, y=0;
	int date = 0;
};
int xx[4] = { 0,1,-1,0 };
int yy[4] = { 1,0,0,-1 };
queue<tom> q;
int arr[1001][1001] = { 0, };
bool visit[1001][1001] = { false, };
int main() {
	//freopen("test.txt", "r", stdin);
	cin >> w >> h;
	int allcnt = w * h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tom tt;
				tt.x = j;
				tt.y = i;
				visit[i][j] = true;
				q.push(tt);
			}
			else if (arr[i][j] == -1) {
				allcnt--;
			}
		}
	}
	tom cur,tmp;
	int nx, ny;
	int lst=-1;
	while (!q.empty()) {
		cur = q.front();
		allcnt--;
		if (lst < cur.date) lst = cur.date;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h && !visit[ny][nx] && arr[ny][nx]!=-1) {
				visit[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.date = cur.date + 1;
				q.push(tmp);
			}
		}
	}
	lst = (allcnt == 0 ? lst : -1);
	cout << lst;
	return 0;
}