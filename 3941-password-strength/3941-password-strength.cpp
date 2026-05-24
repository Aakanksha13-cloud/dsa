class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        unordered_map<char,int> m;
        int n=password.length();
        for(int i=0;i<n;i++){
            char ch=password[i];
            m[ch]++;
            int c=ch-'0';
            if(m[ch]==1){
                if(ch>='a' && ch<='z')ans++;
                else if(ch>='A' && ch<='Z')ans+=2;
                else if(c>=0 && c<=9)ans+=3;
                else if(ch=='!'||ch=='@'||ch=='#' || ch=='$')ans+=5;
            }
         }
        return ans;
}
};