#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;


int main() {
freopen("sample_input.txt", "r", stdin);
int T,N,M;
cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cin>>M;
		int total = 0;
		vector<int> W;
		priority_queue<int,vector<int>,greater<int>> Ridx;
		vector<int> R;
		queue<int> wait;
		vector<int> visit(M,0);
		for (int j = 0; j < N; j++) {
			int r=0;
			cin >> r;
			R.push_back(r);
			Ridx.push(j);
		}
		for (int j = 0; j < M; j++) {
			int w = 0;
			cin >> w;
			W.push_back(w);
		}
		for (int j = 0; j < W.size() * 2; j++) {
			int cur = 0;
			cin >> cur;//cur을 받고 cur에 대한 일을 함
			if (cur < 0) {//차가 빠짐
				cur *= (-1);
				Ridx.push(visit[cur - 1]);//다시 주차장이 비게됨
				if (!wait.empty()) {//웨이팅이 있으면 들여보네주기
					cur = wait.front();
					wait.pop();
					visit[cur - 1] = Ridx.top();
					total += (R[Ridx.top()]*W[cur - 1]);//요금
					Ridx.pop();
				}
			}
			else {//차가 들어옴
				if (!Ridx.empty()) {//주차장이 꽉찬상태가 아니라면
					if (!wait.empty()) {//웨이팅이 있으면 먼저 들여보네주기
						wait.push(cur);
						cur = wait.front();
						wait.pop();
					}
					visit[cur - 1] = Ridx.top();
					total += (R[Ridx.top()]*W[cur - 1]);//요금
					Ridx.pop();
				}
				else {
					wait.push(cur);//waiting 리스트에 추가
				}
			}
		}
		cout << "#" << i + 1 << " ";
		cout << total << endl;
	}
return 0;
}