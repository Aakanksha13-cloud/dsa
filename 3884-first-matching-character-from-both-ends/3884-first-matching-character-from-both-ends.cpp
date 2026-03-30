class Solution {
public:
    int firstMatchingIndex(string s) {
        int i=0;
        int n=s.length();
        while(i<n && n-i-1>=0){
            if(s[i]==s[n-i-1])return i;
            i++;
        }
        return -1;
    }
};