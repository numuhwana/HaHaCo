#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
struct obj{
	int x, y;
	int time=0;
};
void spread() {

}
int main() {
	freopen("불.txt", "r", stdin);
	int TC;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		int w, h;
		cin >> w >> h;
		queue<obj> qf;//불에 대한 queue
		queue<obj> qp;//사람에 대한 queue
		vector<vector<char>> v;
		bool visit[1001][1001] = { 0, };
		for (int i = 0; i < h; i++) {
			vector<char> v2;
			for (int j = 0; j < w; j++) {
				char tmp;
				cin >> tmp;
				v2.push_back(tmp);
				if (tmp == '*') {//불인경우
					obj fire;
					fire.x = j;
					fire.y = i;
					qf.push(fire);
					visit[i][j] = true;
				}
				else if (tmp == '@') {
					obj person;
					person.x = j;
					person.y = i;
					qp.push(person);
					visit[i][j] = true;
				}
				else if(tmp=='#'){
					visit[i][j] = true;//벽이므로
				}
			}
			v.push_back(v2);
		}//여기까지 map과 사람,불 초기화 완료
		obj curp,curf;
		int nx, ny;
		int curt = 0;
		bool finish = false;
		while (!finish && (!qp.empty() || !qf.empty()))//둘중 하나라도 갈길이 더이상 없다면
		{
			while (!qf.empty() && qf.front().time==curt) {//현재시간이랑 같은애들은 퍼트린다
				curf = qf.front();
				qf.pop();
				for (int i = 0; i < 4; i++) {//모든 방향에 대해서 퍼진다.
					nx = curf.x + xx[i];
					ny = curf.y + yy[i];
					if (nx >= 0 && ny >= 0 && nx < w && ny < h && (v[ny][nx]=='.' || v[ny][nx]=='@')) {//불은 범위 안에서만 퍼진다.
						visit[ny][nx] = true;
						v[ny][nx] = '*';
						obj fire;
						fire.x = nx;
						fire.y = ny;
						fire.time = curt + 1;
						qf.push(fire);
					}
				}
			}
			while (!qp.empty() && !finish && qp.front().time == curt) {
				curp = qp.front();
				qp.pop();
				for (int i = 0; i < 4; i++) {
					nx = curp.x + xx[i];
					ny = curp.y + yy[i];
					if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
						if (!visit[ny][nx]) {//갈수 있는 길인경우
							visit[ny][nx] = true;
							obj pers;
							pers.x = nx;
							pers.y = ny;
							pers.time = curt + 1;
							qp.push(pers);
						}
					}
					else {//범위를 벗어나는 경우 현재 시간 출력 끝~
						finish = true;
						cout << curt + 1 << endl;
						break;
					}
				}
			}
			curt++;
		}
		if (!finish) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}