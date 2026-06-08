class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i;
            int len = 0;
            // Find words that fit in current line
            while (j < n &&
                   len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }
            int gaps = j - i - 1;
            string line;
            // Last line OR only one word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += ' ';
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int totalSpaces = maxWidth - len;
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    int spaces =
                        baseSpaces +
                        (extraSpaces > 0 ? 1 : 0);
                    line += string(spaces, ' ');
                    if (extraSpaces > 0)
                        extraSpaces--;
                }
                line += words[j - 1];
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};