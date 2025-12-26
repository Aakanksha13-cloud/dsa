class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
        int m=mat.size();
        int n= mat[0].size();
         vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> drn ={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto frontNode= q.front();
            q.pop();
            int r = frontNode.first;
            int c = frontNode.second;
            for(auto d:drn){
                int nr=r+d[0];
                int nc= c+d[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && ans[nr][nc]==-1){
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};