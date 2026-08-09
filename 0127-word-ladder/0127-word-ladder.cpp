class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //shortest path->bfs
        unordered_set<string> s(wordList.begin(),wordList.end());
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        pq.push({1,beginWord});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int dist=t.first;
            string str=t.second;
            if(str==endWord)return dist;
            for(int i=0;i<str.length();i++){
                char org=str[i];
                for(char j='a';j<='z';j++){
                    str[i]=j;
                    if(s.find(str)!=s.end()){
                        pq.push({dist+1,str});
                        s.erase(str); 
                    }
                }
                str[i]=org;
            }
        }
        return 0;
    }
};