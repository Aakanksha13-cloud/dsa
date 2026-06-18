class Solution {
public:
    long long halveSteps(long long val, long long target) {
        long long steps = 0;
        while (val > target) {
            if (val % 2 != 0) return -1;
            val /= 2;
            steps++;
        }
        return (val == target) ? steps : -1;
    }
    int minMoves(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return 0;
        if (sx == 0 && sy == 0) return -1; // stuck at the origin forever

        long long X = tx, Y = ty, count = 0;
        const long long MAXITER = 300; // generous safety bound (~O(log) needed)
        long long iter = 0;

        while (true) {
            if (++iter > MAXITER) return -1;

            if (X == sx && Y == sy) return count;
            if (X < sx || Y < sy || X < 0 || Y < 0) return -1;
            if (X == 0 && Y == 0) return -1;

            if (X == Y) {
                // X == Y > 0 here -> two possible predecessors: (X,0) and (0,X)
                long long best = -1;
                if (sy == 0) {
                    long long r = halveSteps(X, sx);
                    if (r != -1 && (best == -1 || r < best)) best = r;
                }
                if (sx == 0) {
                    long long r = halveSteps(X, sy);
                    if (r != -1 && (best == -1 || r < best)) best = r;
                }
                return (best == -1) ? -1 : count + 1 + best;
                } else if (X > Y) {
                if (Y == 0) {
                    if (sy != 0) return -1;
                    long long r = halveSteps(X, sx);
                    return (r == -1) ? -1 : count + r;
                }
                if (X > 2 * Y) {
                    if (X % 2 != 0) return -1;
                    X /= 2;
                } else {
                    X -= Y;
                }
                count++;
            } else { // Y > X
                if (X == 0) {
                    if (sx != 0) return -1;
                    long long r = halveSteps(Y, sy);
                    return (r == -1) ? -1 : count + r;
                }
                if (Y > 2 * X) {
                    if (Y % 2 != 0) return -1;
                    Y /= 2;
                } else {
                    Y -= X;
                }
                  count++;
            }
        }
    }
};