class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length())return false;
        if(s=="")return true;
        // unordered_map<char,int> m;
      
        // for(int i=0;i<t.size();i++){
        //     m[t[i]]=i;
        // }
        // int prev=0;
        // if(m.find(s[0])!=m.end())prev=m[s[0]];
        // else return false;
        // for(int i=1;i<s.length();i++){
        //     if(m.find(s[i])!=m.end()){
        //         int curr=m[s[i]];
        //         if(curr>prev)prev=curr;
        //         else{
        //             return false;
        //             break;
        //         }
        //     }

        //     else return false;
        // }
        // return true;
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j])i++;
            j++;
        }
        return i==s.length();
    }
};