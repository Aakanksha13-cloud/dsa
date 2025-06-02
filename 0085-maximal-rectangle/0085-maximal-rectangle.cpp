class Solution {
public:
    int maxarea(vector<int>& hist){
       stack<int> s;
        hist.push_back(0); // Sentinel to flush the stack
        int maxArea = 0;

        for (int i = 0; i < hist.size(); ++i) {
            while (!s.empty() && hist[i] < hist[s.top()]) {
                int height = hist[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }

        hist.pop_back(); // Remove sentinel
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> hist(col,0);
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1')hist[j]+=1;
                else hist[j]=0;
            }
            ans = max(ans,maxarea(hist));
        }
        return ans;
    }
};