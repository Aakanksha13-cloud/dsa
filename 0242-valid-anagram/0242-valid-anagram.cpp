class Solution {
public:
    bool isAnagram(string s, string t) {
        //onlogn
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s.compare(t)==0)
        // return true;

        // return false;   

        if(s.length()!=t.length())return false;
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[(s[i]-'a')]++;
            count[(t[i]-'a')]--;
        } 
        for(int i:count){
            if(i!=0)return false;
        }
        return true;
    }     
    
};