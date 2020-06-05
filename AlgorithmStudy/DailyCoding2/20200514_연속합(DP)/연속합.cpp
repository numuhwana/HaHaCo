#include <iostream>
#include <vector>
//#pragma warning (disable:4996)
using namespace std;
vector<int> arr;
int main() {
	//freopen("연속합.txt", "r", stdin);
	int ct = 0,tmp,cursum=-1001,tsum=-1001;
	cin >> ct;
	for (int i = 0; i < ct; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 0; i < arr.size(); i++) {
		if (cursum + arr[i] > arr[i]) cursum += arr[i];
		else cursum = arr[i];
		if (tsum < cursum) tsum = cursum;
	}
	cout << tsum << endl;
	return 0;
}