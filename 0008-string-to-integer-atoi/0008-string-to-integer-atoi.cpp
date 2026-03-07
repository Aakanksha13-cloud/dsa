class Solution {
public:
    int myAtoi(string s) {
        // int num=0, i=0, sign =1;
        // while(s[i]==' '){
        //     i++;
        // }
        // if(s.size()>i && (s[i]=='+'|| s[i]=='-')){
        //     sign = s[i]=='-' ? -1 : 1;
        //     i++;
        // }
        // while(i<s.size()&& isdigit(s[i])){
        //     if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i]>'7')){
        //         return sign==-1 ? INT_MIN : INT_MAX;
        //     }
        //     num = num*10 + (s[i]-'0');
        //     i++;
        // }
        // return num*sign;
        int num=0;
        int sign=1;
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' ')i++;
        if(i<n &&(s[i]=='-' || s[i]=='+')){
            sign = s[i]=='-' ? -1 : 1;
            i++;
            }
        while(i<n && s[i]=='0')i++;

        while(i<n && isdigit(s[i])){
            if(num > INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7'))return sign==-1?INT_MIN :INT_MAX;
            num= num*10 +( s[i]-'0');
            i++;
        }
        return num*sign;
    }
};