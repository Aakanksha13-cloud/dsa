class Solution {
public:
    long long opsNeeded(const vector<int>& nums, long long k) {
        long long ops = 0;

        for (int x : nums) {
            ops += (x + k - 1) / k;   // ceil(x / k)

            // Prevent unnecessary overflow/work
            if (ops > k * k) return ops;
        }

        return ops;
    }
    int minimumK(vector<int>& nums) {
        long long lo = 1, hi = 1;

        auto good = [&](long long k) {
            return opsNeeded(nums, k) <= k * k;
        };

        while (!good(hi)) hi *= 2;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (good(mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return (int)lo;
    }
};