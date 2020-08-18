#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int main() {
    int N, C;
    //freopen("공유기설치.txt", "r", stdin);
    cin >> N >> C;//N은 집의 수 C는 공유기 개수
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int lt = 1;
    int rt = v[v.size() - 1]-v[0];//가장 최장길이
    int md = 0;
    int longest = rt;
    while (lt < rt) {//길이가 하나로 수렴할때까지
        md = (rt + lt) / 2;//중간 길이값으로 먼저 설정하기
        int cnt = 1;//공유기 개수
        int st = v[0];
        for (int i = 0; i < v.size(); i++) {
            if ((v[i] - st) >= md) {//st는 이전에 공유기가 설치된곳의 좌표이고 현재좌표와의 차가 md의 길이보다 작거나 같은경우 cnt++
                cnt++;
                st = v[i];//이전 공유기가 설치된곳은 st로 초기화
            }
        }
        if (cnt < C) {//md값이 너무 커서 공유기를 전부 설치가 불가능한경우 md는 더 줄여야한다.
            rt = md;
        }
        else {//md는 더 커질수 있는 경우 하지만 현재까지 될수 있는 최장길이로 저장한다.
            lt = md+1;
            longest = md;
        }
    }
    cout << longest << endl;

    return 0;
}