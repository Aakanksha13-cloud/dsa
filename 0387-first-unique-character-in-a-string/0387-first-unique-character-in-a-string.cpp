class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        queue<int>q;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
            if(freq[s[i]]==1)q.push(i);
            // if(!q.empty() && freq[s[q.front()]]>1)q.pop();
        }
        while(!q.empty() && freq[s[q.front()]]>1)q.pop();
        if(q.size()>0)return q.front();
        else return -1;
        
    }
};