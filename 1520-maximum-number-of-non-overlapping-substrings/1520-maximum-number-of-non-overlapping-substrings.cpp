class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
       vector<int> first(26, n), last(26, -1);

    // Step 1: first and last occurrence
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        first[c] = min(first[c], i);
        last[c] = max(last[c], i);
    }

    vector<pair<int,int>> intervals;

    // Step 2: find minimal valid intervals
    for (int c = 0; c < 26; c++) {
        if (first[c] == n) continue;

        int l = first[c], r = last[c];
        bool valid = true;

        for (int i = l; i <= r; i++) {
            int d = s[i] - 'a';
            if (first[d] < l) {
                valid = false;
                break;
            }
            r = max(r, last[d]);
        }

        if (valid) intervals.push_back({l, r});
    }

    // Step 3: greedy by ending point
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) {
             return a.second < b.second;
         });

    vector<string> ans;
    int prevEnd = -1;

    for (auto &in : intervals) {
        if (in.first > prevEnd) {
            ans.push_back(s.substr(in.first, in.second - in.first + 1));
            prevEnd = in.second;
        }
    }

    return ans;
    }
};