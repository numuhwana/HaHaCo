#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
static long INF = 500 * 10000;
int main() {
	freopen("타임머신.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	long long v[501] = { 0, };//
	for (int i = 2; i <= N; i++) {
		v[i] = INF;//최대거리로 초기화
	}
	vector<long long> A(M,0),B(M,0), C(M,0);
	for (int i = 0; i < M; i++) {//연결해주기
		long long a, b, c;
		cin >> a >> b >> c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	for (int i = 0; i < N;i++) {//Nq번 반복
		for (int j = 0; j < M; j++) {
			if (v[A[j]] != INF) {//INF가 아니면 연결해줄지 고민하기
				long long cur = v[A[j]] + C[j];//연결했을때의 time
				if (cur < v[B[j]])//더 작으면 업데이트
				{
					v[B[j]] = cur;
				}
			}
		}
	}
	bool cycle = false;
	for (int j = 0; j < M; j++) {//사이클 확인
		if (v[A[j]] != INF) {//INF가 아니면 연결해줄지 고민하기
			long long cur = v[A[j]] + C[j];//연결했을때의 time
			if (cur < v[B[j]])//더 작으면 이건 무한대 과거로감
			{
				cycle = true;
				break;
			}
		}
	}
	if (!cycle) {
		for (int i = 2; i <= N; i++) {
			cout << (v[i]== INF?-1:v[i]) << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}