class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        while(s[i]==' '){
            n--;
            i--;
        }
        int lastgap=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                lastgap=i;
                break;
            }
        }
        if(lastgap==-1)return n;
        int ans=n-lastgap-1;
        return ans;
    }
};