#include <iostream>
#include <queue>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
int w, h,nx,ny;
struct bing {
	int x, y;//좌표
	int hour=0;//시간
	int bingnum = 0;//높이
};
int arr[301][301] = { 0, };
int xx[4] = { 0,-1,1,0 };
int yy[4] = { -1,0,0,1 };
queue<bing> q,zero;
/*void print(int a[301][301]) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << " ";
		}cout << endl;
	}cout << endl;
}*/
bool isseperated(int size,bing cur) {
	vector<vector<bool>> visit(h, vector<bool>(w, false));
	queue<bing> q2;
	visit[cur.y][cur.x] = true;
	q2.push(cur);
	bing c,tmp;
	int cnt = 0;
	while (!q2.empty()) {
		cnt++;
		c = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			nx = c.x + xx[i];
			ny = c.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h) {//주변에 물이 있는지 확인
				if (!visit[ny][nx] && arr[ny][nx] > 0) {
					visit[ny][nx] = true;
					tmp.x = nx;
					tmp.y = ny;
					q2.push(tmp);
				}
			}
		}
	}
	return (size == cnt ? false : true);
}

int main() {
	//freopen("test.txt", "r", stdin);
	cin >> h >> w;

	bing cur,tmp;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin>>arr[i][j];
			if (arr[i][j] > 0) {
				cur.x = j;
				cur.y = i;
				cur.bingnum = arr[i][j];
				q.push(cur);
			}
		}
	}
	int minus = 0, curhour=0;
	if (q.size() == (h*w)) { cout << 0; return 0; }
	while (!q.empty()) {
		cur = q.front();
		minus = 0;
		if (curhour < cur.hour) {
			bing t;
			while (!zero.empty()) {
				t = zero.front();
				arr[t.y][t.x] = 0;
				zero.pop();
			}
			//print(arr);
			//여기서 땅이 갈라졌는지 확인
			if (isseperated(q.size(),cur)) { 
				cout << cur.hour;
				return 0;
			}
			curhour = cur.hour;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h && arr[ny][nx]==0) {//주변에 물이 있는지 확인
				minus++;
			}
		}
		cur.hour++;
		cur.bingnum = cur.bingnum - minus;
		if (cur.bingnum > 0) {//빙산이 다 녹아버리면 없애버린다.
			q.push(cur);
			arr[cur.y][cur.x] = cur.bingnum;
		}
		else {//빙산이 0이 된애들은 zero에 넣는다.
			zero.push(cur);
		}

	}
	cout << 0;
	return 0;

}