class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;
        int ans=INT_MIN;
        unordered_map<char,int> m;        
        for(int i=0;i<s.length();i++){
            int len=0;
            for(int j=i;j<s.length();j++){
                
                m[s[j]]++;
                if(m[s[j]]>1){
                    m.clear();
                    break;
                }
                len=j-i+1;
                ans=max(ans,len);
            }
        }
        return ans;
    }
};