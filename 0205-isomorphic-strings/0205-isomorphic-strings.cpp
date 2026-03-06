class Solution {
public:
    // void mappedStr(string &str){
    //     unordered_map<char,char>mapping;
    //     char start = 'a';
    //     int i =0;
    //     while(i< str.length()){
    //         if(mapping.find(str[i]) == mapping.end()){
    //             mapping[str[i]] = start;
    //             start++;
    //             i++;
    //         }
    //         else i++;
    //     }
    //     for(int i =0; i<str.length(); i++){
    //         str[i] = mapping[str[i]];
    //     }
    // }
    bool isIsomorphic(string s, string t) {
        // mappedStr(s);
        // mappedStr(t);
        // if(s.compare(t)==0)
        //  return true;
        // return false; 
        if(s.length()!=t.length())return false;
        int m1[256]={0};
        int m2[256]={0};
        for(int i=0;i<s.length();i++){
            if(m1[s[i]]!=m2[t[i]])return false;
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};