class Solution {
public:
    // bool isPal(string&str, int start, int end){
    //     while(start<end){
    //         if(str[start]!=str[end]){
    //             return false;
    //         }
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
    string longestPalindrome(string s) {
        // string ans ="";
        // for(int i=0; i<s.length(); i++){
        //     for(int j=i; j<s.length();j++){
        //      if(isPal(s,i,j)){
        //         string p = s.substr(i,j-i+1);
        //         ans = ans.length()<p.length() ? p : ans;
        //      }
        //     }
        // }
        // return ans;
        int start=0;
        int maxlen=1;
        for(int i=0;i<s.length();i++){
            int l=i;
            int r=i;
            while(l<=r && l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }

            l=i;
            r=i+1;
            while(l<=r && l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>maxlen){
                    start=l;
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }

        }
        return s.substr(start,maxlen);
    }
};