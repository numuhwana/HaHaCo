#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long mx=(long long)times[times.size()-1]*n;//최대 걸리는 시간
    long long mn=1;
    long long mid=0;
    while(mn<mx){
        mid=(mx+mn)/2;
        long long sum=0;
        for(int i=0;i<times.size();i++){
            sum+=mid/times[i];//현재 times에 대한 명수
        }
        if(sum<n) mn=mid+1;//시간을 너무 적게 잡았다.
        else{
            if(sum>=n){
                answer=mid;
            }
            mx=mid-1;
        }
    }
    return answer;
}