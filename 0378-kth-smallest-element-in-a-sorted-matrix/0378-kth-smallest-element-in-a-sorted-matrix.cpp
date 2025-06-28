class Info{
    public:
    int data;
    int row;
    int col;
    Info(int a, int b, int c){
        this->data=a;
        this->row=b;
        this->col=c;
    }
};
class compare{
    public:
    bool operator()(Info* a,Info* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<Info*, vector<Info*>, compare> pq;
        for(int i=0;i<n;i++){
            Info* temp= new Info(matrix[i][0],i,0);
            pq.push(temp);
        }
        int ans;
        int count=0;
        while(!pq.empty()){
                Info* temp= pq.top();
                int tdata= temp->data;
                int r= temp->row;
                int c=temp->col;
                pq.pop();
                ans=tdata;
                count++;
                if(c+1<n){
                    Info* ele= new Info(matrix[r][c+1],r,c+1);
                    pq.push(ele);               
                }
            if(count==k)break;
        }
        return ans;
    }
};