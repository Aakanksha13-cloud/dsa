class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for (int k = 2; k <= n; k++) {
            string next = "";
            int i = 0;
            while (i < curr.size()) {
                int count = 1;
                while (i + 1 < curr.size() &&
                       curr[i] == curr[i + 1]) {
                    count++;
                    i++;
                }
                next += to_string(count);
                next += curr[i];
                i++;
            }
            curr = next;
        }
        return curr;
    }
};