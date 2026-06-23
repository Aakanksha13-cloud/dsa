class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            vector<int> lis;

            for (int x : nums) {
                if ((x >> bit) & 1) {
                    auto it = lower_bound(lis.begin(), lis.end(), x);

                    if (it == lis.end())
                        lis.push_back(x);
                    else
                        *it = x;
                }
            }

            ans = max(ans, (int)lis.size());
        }

        return ans;
    }
};