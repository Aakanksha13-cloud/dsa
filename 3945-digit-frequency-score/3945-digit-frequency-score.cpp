class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> m;
        string s= to_string(n);
        for(int i=0;i<s.length();i++){
            int x= s[i]-'0';
            m[x]++;
        }
        int ans=0;
        for(auto it:m){
            int a=it.first;
            int b=it.second;
            ans+= a * b;
        }
        return ans;
    }
};