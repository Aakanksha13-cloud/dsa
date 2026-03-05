class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int ans=0;
        string a(n,' ');
        string b(n,' ');
        for(int i=0;i<n;i+=2){
            a[i]='0';
            b[i]='1';
        }
        for(int i=1;i<n;i+=2){
            a[i]='1';
            b[i]='0';
        }
        int mina=0;
        int minb=0;
        for(int i=0;i<n;i++){
            if(s[i]!=a[i])mina++;
            if(s[i]!=b[i])minb++;
        }
        ans=min(mina,minb);
        return ans;
    }
};