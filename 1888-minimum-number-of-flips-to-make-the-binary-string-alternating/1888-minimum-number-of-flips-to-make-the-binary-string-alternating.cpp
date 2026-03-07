class Solution {
public:
    int minFlips(string s) {    
       int n=s.length();
       s=s+s;
       string s1(2*n,' ');
       string s2(2*n,' ');
       for(int i=0;i<2*n;i+=2){
        s1[i]='0';
        s2[i]='1';
       }
       for(int i=1;i<2*n;i+=2){
        s1[i]='1';
        s2[i]='0';
       }
       int n1=0;
       int n2=0;
       int ans=INT_MAX;
       for(int i=0;i<2*n;i++){
        if(s1[i]!=s[i])n1++;
        if(s2[i]!=s[i])n2++;
        if(i>=n){
            if(s1[i-n]!=s[i-n])n1--;
            if(s2[i-n]!=s[i-n])n2--;
        }
        if(i>=n-1)ans=min(ans,min(n1,n2));
       }
       return ans;
}
};