#include <iostream>
#include <queue>

#pragma warning(disable:4996)
using namespace std;
int xx[] = { 0,0,-1,-1,-1,0,1,1,1 };
int yy[] = { 0,-1,-1,0,1,1,1,0,-1 };
//0: 제자리 1:↑, 2:↖,3: ←, 4:↙, 5:↓,6: ↘,7:→,8:↗
int mx = 0;
struct fish {
	int x = 0;
	int y = 0;
	int dir=0;
	int num=0;
	bool live = true;
};
struct shark {
	int x=0;
	int y=0;
	int total = 0;
	int dir=0;
};
fish ff[17];
int map[4][4] = { 0, };
void copystate(int from[][4], int to[][4],fish from2[],fish to2[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			to[i][j] = from[i][j];
		}
	}
	for (int i = 1; i < 17; i++) {
		to2[i] = from2[i];
	}
}
void swapfish(fish &a, fish &b) {
	map[a.y][a.x] = b.num;
	map[b.y][b.x] = a.num;
	fish tmp = a;
	a.x = b.x;
	a.y = b.y;
	b.x = tmp.x;
	b.y = tmp.y;
}
void movefish() {
	int nx, ny;
	for (int i = 1; i < 17; i++) {//모든 물고기에 대해서 돌기
		if (ff[i].live) {//살아있는 경우에만
			int curdir = ff[i].dir;//현재 방향 넣기
			nx = ff[i].x + xx[curdir];
			ny = ff[i].y + yy[curdir];
			bool ch = false;
			while (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || map[ny][nx]<0) {//방향 정해주기
				curdir++;
				if (curdir == 9) curdir = 1;//인덱스 범위 넘어가면
				if (curdir == ff[i].dir) {//한바퀴 돌아서 다시 같아졌을때
					ch = true;
					break;//계속 돌다가 원래를 만난경우
				}
				nx = ff[i].x + xx[curdir];
				ny = ff[i].y + yy[curdir];
			}
			if (!ch) {
				ff[i].dir = curdir;//방향 바꿔주고 방향의 물고기와 스위치
				if (map[ny][nx] == 0) {
					map[ny][nx] = ff[i].num;
					map[ff[i].y][ff[i].x] = 0;
					ff[i].x = nx;
					ff[i].y = ny;
				}
				else {
					swapfish(ff[i], ff[map[ny][nx]]);
				}
			}
		}
	}
}

void eatfish(bool eat,int ny,int nx,shark &cur,int curfish) {//
	if (eat) {//먹을때 shark의 방향 자리 다 바꾸기
		map[cur.y][cur.x] = 0;//현재 상어의 위치는 비어있는걸로
		map[ny][nx] = -1;//다음 상어의 위치는 -1인걸로
		//상어 이동
		cur.y = ny;
		cur.x = nx;
		cur.total += curfish;//상어 먹은거 total 업데이트
		cur.dir = ff[curfish].dir;//다음 위치의 물고기에서 방향 가져오기
		ff[curfish].live = false;//물고기 쥬금s
	}
	else {//다시 되돌릴때
		map[cur.y][cur.x] = curfish;//상어위치 빡구
		map[ny][nx] = -1;
		ff[curfish].live = true;//물고기 다시 부활

	}
}
void dfs(shark s) {//물고기 움직이고~ 상어 움직이는 dfs
	mx = max(s.total, mx);//먹은 개수가 크면 저장
	//map의 상태 복사 해놓기
	int tmp[4][4] = { 0, };
	fish tmpf[17];
	copystate(map, tmp,ff,tmpf);
	movefish();//그다음에 물고기들 움직여주기
	//print2(tmp);
	//선택지는 최대 3가지
	int nx, ny;
	for (int i = 1; i < 4; i++) {
		nx = s.x + (xx[s.dir]*i);
		ny = s.y + (yy[s.dir] * i);
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && map[ny][nx]>0) {//범위 안이고 물고기가 있는경우에만 이동
			//다음위치로 갈때 fish 먹기
			shark tmp2;
			tmp2 = s;//상어 현재위치 일단 저장
			int curfish = map[ny][nx];//현재 물고기 크기 저장
			eatfish(true,ny,nx,s,curfish );//다음 위치를 미리 먹는다. (상어상태도 변함)
			//print(s);
			dfs(s);//바뀐 상어위치 기준
			eatfish(false, tmp2.y, tmp2.x, s, curfish);//상태 되돌리기
			s = tmp2;//상어 다시 되돌리기
		}
		
	}
	copystate(tmp, map,tmpf,ff);//다시 맵상태 되돌려주기
}
int main() {
	//freopen("청소년상어.txt", "r", stdin);
	//freopen("결과.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fish f;
			cin >> f.num >> f.dir;
			f.x = j;
			f.y = i;
			ff[f.num] = f;
			map[i][j] = f.num;
		}
	}//나머지 16마리의 물고기들
	shark s;
	s.x = 0;
	s.y = 0;
	s.dir = ff[map[0][0]].dir;//0,0번째의 물고기의 방향
	s.total = ff[map[0][0]].num;
	ff[map[0][0]].live = false;
	map[0][0] = -1;
	//처음에는 무조건 0,0에 있는 애를 먹는다
	dfs(s);//그다음부터 시작
	cout << mx<<endl;
	return 0;
}