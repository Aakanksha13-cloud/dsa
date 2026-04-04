class Solution {
public:
    int lengthLongestPath(string input) {
       // all /n & /t are replaced by single / 
       // opt 1- tree nut ig lengthy 
       //opt 2- stack
       int maxlen=0;
       stack<int> s;
       stringstream ss(input);
       string curfile;
       while(getline(ss,curfile,'\n')){
           int len= curfile.length();
           int level=0;
           //tab is in starting...so have to calc level by tabs at begining
           while(level<len && curfile[level]=='\t')level++;
           len=len-level;
           while(level<s.size())s.pop();

           if(level!=0)len = len+1+s.top();
           s.push(len);
           if(curfile.find('.')!=string::npos)maxlen=max(maxlen,s.top());
       }
       return maxlen;
    }
};