class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        if(n==1)return true;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1] && s[i]=='1')return false;
        }
        return true;
    }
};