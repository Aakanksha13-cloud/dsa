class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;

    void dfs(string word,
             string beginWord,
             vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(
            wordList.begin(),
            wordList.end()
        );

        if (!dict.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> level;
        level[beginWord] = 0;

        bool found = false;

        while (!q.empty() && !found) {

            int sz = q.size();
            unordered_set<string> usedThisLevel;

            while (sz--) {

                string word = q.front();
                q.pop();

                int currLevel = level[word];

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        temp[i] = ch;

                        if (!dict.count(temp))
                            continue;

                        if (!level.count(temp)) {

                            level[temp] = currLevel + 1;
                            q.push(temp);

                            parents[temp].push_back(word);

                            usedThisLevel.insert(temp);
                        }
                        else if (level[temp] ==
                                 currLevel + 1) {

                            parents[temp].push_back(word);
                        }

                        if (temp == endWord)
                            found = true;
                    }

                    temp[i] = original;
                }
            }

            for (auto &w : usedThisLevel)
                dict.erase(w);
        }

        if (!found)
            return {};

        vector<string> path = {endWord};

        dfs(endWord, beginWord, path);

        return ans;
    }
};