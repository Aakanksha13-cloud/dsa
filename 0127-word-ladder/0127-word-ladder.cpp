class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string frontSt= q.front().first;
            int frontDist= q.front().second;
            q.pop();
            if(frontSt==endWord)return frontDist;
            else{
                for(int i=0;i<frontSt.size();i++){
                    char originalch= frontSt[i];
                    for(char ch='a';ch<='z';ch++){
                        frontSt[i]=ch;
                        if(st.find(frontSt)!=st.end()){
                            q.push({frontSt,frontDist+1});
                            st.erase(frontSt);
                        }
                    }
                    //backtrack
                    frontSt[i]=originalch;
                }
            }
        }
        return 0;
    }
};