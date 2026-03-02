class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> maxright(n);
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    maxright[i]=j;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            //we want row j>=i such that maxright[j]<=i
            int j=i;
            while(j<n && maxright[j]>i){
                j++;
            }
            //now we've got j
            if(j==n)return -1;
            while(j>i){
                swap(maxright[j-1],maxright[j]);
                ans++;
                j--;
            }
        }
        // for(int i=0;i<n;i++){
        //         if(maxright[i]>i)return -1;    
        // }
        return ans;

    }
};