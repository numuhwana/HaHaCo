#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#pragma warning(disable:4996)
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	for (int z = 0; z < 10; z++) {
		int cnt=0;
		int N = 0;
		cin >> N;
		vector<int> arr(N, 0);//원래 사이즈 앞뒤로 두개 추가해야함
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		int L = 0, R = 0;
		for (int i = 2; i < arr.size() - 2; i++) {
			L = max(arr[i - 2], arr[i - 1]);
			R = max(arr[i + 1], arr[i + 2]);
			int mx = max(L, R);
			if (arr[i] > mx) {
				cnt += arr[i] - mx;
			}
		}
		cout << "#" << z + 1 << " " << cnt << endl;
	}
	return 0;
}