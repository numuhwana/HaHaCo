class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt=0;
        unordered_map<char,bool> m;
        for(int i=0;i<J.size();i++){
            m[J[i]]=true;
        }
        for(int i=0;i<S.size();i++){
            if(m.find(S[i])!=m.end()){
                cnt++;
            }
        }
        return cnt;
    }
};