#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
	freopen("나무자르기.txt", "r", stdin);
	long long N, M;
	cin >> N >> M;
	long long mx;
	vector<long long> v;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
		mx = max(mx, tmp);
	}
	long long lt=0, rt=mx;
	long long mid;
	long long res=0;
	while (lt <= rt) {
		mid = (lt + rt) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
		if (v[i] >= mid) {//나무 길이가 mid보다 큰경우
			sum += v[i] - mid;//뺀거 더하기
			}
		}
		if (sum >= M) {//나무가 더 높아져도 될 경우
			if(res<mid) res = mid;
			lt = mid + 1;
		}
		else {//나무가 부족한경우
			rt = mid-1;
		}
	}
	cout << res;
	return 0;
}