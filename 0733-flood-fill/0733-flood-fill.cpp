class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int color){
        int m= image.size();
        int n = image[0].size();
        vector<vector<int>> drn= {{-1,0},{1,0},{0,1},{0,-1}};
        for(auto d:drn){
            int nr = i+d[0];
            int nc = j+d[1];
            if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc]==color && image[nr][nc]!=image[i][j]){
                image[nr][nc]= image[i][j];
                dfs(nr,nc,image,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalCol = image[sr][sc];
        if(image[sr][sc]==color)return image;
        image[sr][sc] = color;
        dfs(sr,sc,image,originalCol);
        return image;
    }
};