class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans="";
        vector<string> rows(numRows);
        bool down=false;
        int curRow=0;
        for(int i=0;i<s.length();i++){
            rows[curRow]+=s[i];
            if(curRow==0 || curRow==numRows-1)down=!down;
            curRow+= down ?1:-1;
        }
        for(int i=0;i<numRows;i++){
            ans+=rows[i];
        }
        return ans;
    }
};