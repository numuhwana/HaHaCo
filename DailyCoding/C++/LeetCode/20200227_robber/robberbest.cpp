 #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {

 int i,n=v.size();
        if(n==0) return 0;
        if(n==1) return v[0];
        if(n==2) return max(v[0],v[1]);
        int A[n];
        A[0]=v[0];
        A[1]=max(v[0],v[1]);
        for(i=2;i<n;i++) A[i]=max((v[i]+A[i-2]),(A[i-1]));
        return A[n-1];

};
int main() {
	vector<int> arr = { 2, 1, 1, 2, 3, 1 };
	vector<int> arr2 = {2,1,1,2,3,3 };
	Solution sol = Solution();
	cout<<sol.rob(arr2);
	return 0;
}