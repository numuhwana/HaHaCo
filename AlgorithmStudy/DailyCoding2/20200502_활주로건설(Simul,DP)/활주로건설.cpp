#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int T = 0,n,x,cnt=0;
int arr[21][21] = { 0, };
int main() {
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	int cur = 0,prev=0;
	for (int t = 0; t < T; t++) {
		cin >> n >> x;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			cur = 0;
			prev = arr[i][0];
			for (int j = 0; j < n; j++) {
				if (prev == arr[i][j]) cur++;
				else if (prev+1 == arr[i][j]) {//전값보다 현재값이 큰경우
					if (cur >= x) {//이전에 2개이상을 이미 쌓아와야지 만족
						cur = 1;//1로 초기화
					}
					else {
						cur = -1;
						break;//이미 만족을 못함
					}
				}
				else if(prev-1==arr[i][j]){//현재값이 더 작은경우
					if (cur < 0) { break; }
					cur = -(x - 1);//-1로 초기화
				}
				else {
					cur = -1;
					break;
				}
				prev = arr[i][j];
			}
			if (cur >= 0) cnt++;//0이상이어야만 경사로 가능
		}
		for (int i = 0; i <n; i++) {
			cur = 0;
			prev = arr[0][i];
			for (int j = 0; j < n; j++) {
				if (prev == arr[j][i]) cur++;
				else if (prev+1 == arr[j][i]) {//전값보다 현재값이 큰경우
					if (cur >= x) {//이전에 2개이상을 이미 쌓아와야지 만족
						cur = 1;//1로 초기화
					}
					else {
						cur = -1;
						break;//이미 만족을 못함
					}
				}
				else if(prev-1==arr[j][i]) {//현재값이 더 작은경우
					if (cur < 0) { break; }
					cur = -(x-1);//-1로 초기화
				}
				else {
					cur = -1;
					break;
				}
				prev = arr[j][i];
			}
			if (cur >= 0) cnt++;//0이상이어야만 경사로 가능
		}
		cout << "#" << t + 1 << " " << cnt<<endl;

	}
	return 0;

}