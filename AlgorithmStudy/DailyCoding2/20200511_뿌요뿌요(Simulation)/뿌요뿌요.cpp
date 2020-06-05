#include <iostream>
#include <vector>
#include <queue>
//#pragma warning(disable:4996)
using namespace std;
struct pu {
	int x, y;
	char c;
};
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
char grid[12][6];
vector<vector<bool>> visit(12, vector<bool>(6, false));
int cnt = 0;
queue<pu> q;
void move(queue<pu> mv) {
	pu cur;
	int nx, ny;
	while (!mv.empty()) {
		cur = mv.front();
		mv.pop();
		if (grid[cur.y][cur.x] != '.') {//.이 아니면 밑에 있는지 확인해서 내린다.
				nx = cur.x + xx[0];
				ny = cur.y + yy[0];
				if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12) {//범위 안이면
					if (grid[ny][nx]=='.') {//.이면 밑으로 내려간다.
						grid[ny][nx] = cur.c;
						grid[cur.y][cur.x] = '.';
						cur.y = ny;
						cur.x = nx;
						mv.push(cur);
					}
				}
		}
	}
}
bool findpop(vector<vector<bool>>& visit) {
	pu cur;
	int nx, ny,pucnt=0;
	queue<pu> yo;
	visit[q.front().y][q.front().x] = true;
	while (!q.empty()) {
		pucnt++;//크기를 잰다.
		cur = q.front();
		yo.push(cur);
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.x + xx[i];
			ny = cur.y + yy[i];
			if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12) {
				if (!visit[ny][nx] && grid[ny][nx]==cur.c) {//이미 들른곳이 아니고 같은 컬러면 q에 넣기
					visit[ny][nx] = true;
					pu nw;
					nw.c = cur.c;
					nw.x = nx;
					nw.y = ny;
					q.push(nw);
				}
			}
		}
	}
	if (pucnt >= 4) {
		while (!yo.empty()) {
			cur = yo.front();
			grid[cur.y][cur.x] = '.';//grid 바꿔주기
			yo.pop();
		}
		return true;
	}
	return false;
}
bool checkall(vector<vector<bool>> visit) {
	bool f=false;
	queue<pu> mv;
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (grid[i][j] != '.') {
				pu p;
				p.x = j;
				p.y = i;
				p.c = grid[i][j];
				mv.push(p);//밑에서부터 차례대로 queue에 넣는다.
				if (!visit[i][j]) {
					q.push(p);
					bool t = findpop(visit);//모든 애들에 대해서 pop해줘야함
					f = (f ? true : t);
				}
			}
		}
	}
	move(mv);
	return f;
}
int main() {
	//freopen("test.txt", "r", stdin);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin>>grid[i][j];
		}
	}
	bool f = false;
	while (1) {
		f = checkall(visit);
		if (!f) {
			cout << cnt;
			return 0;
		}
		cnt++;//연쇄 증가
		f = false;
	}
	return 0;

}