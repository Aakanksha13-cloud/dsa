class Solution {
public:
    void prevSmaller(vector<int>& heights, vector<int>& prevAns){
        // stack<int> s;
        // s.push(-1);
        // for(int i=0;i<heights.size();i++){
        //     int val=heights[i];
        //     while(s.top()!=-1 && heights[s.top()]>=val){
        //         s.pop();
        //     }
        //     prevAns.push_back(s.top());
        //     s.push(i);
        // }
        stack<int> s;
        s.push(-1);
        for(int i=0;i<heights.size();i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i])s.pop();
            prevAns.push_back(s.top());
            s.push(i);
        }
    }

    void nextSmaller(vector<int>& heights, vector<int>& nextAns){
        // stack<int> s;
        // s.push(-1);
        // for(int i=heights.size()-1;i>=0;i--){
        //     int val=heights[i];
        //     while(s.top()!=-1 && heights[s.top()]>=val){
        //         s.pop();
        //     }
        //     nextAns.push_back(s.top());
        //     s.push(i);
        // }
        // reverse(nextAns.begin(),nextAns.end());
        // for(int i=0;i<nextAns.size();i++){
        //     if(nextAns[i]==-1){
        //         nextAns[i]=nextAns.size();
        //     }
        // }
        stack<int>s;
        s.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i])s.pop();
            nextAns.push_back(s.top());
            s.push(i);
        }
        for(int i=0;i<nextAns.size();i++){
            if(nextAns[i]==-1)nextAns[i]=nextAns.size();
        }
        reverse(nextAns.begin(),nextAns.end());
        
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevAns;
        vector<int> nextAns;
        int n = heights.size();
        nextSmaller(heights,nextAns);
        prevSmaller(heights,prevAns);
        int maxans= INT_MIN;
        // for(int i=0;i<n;i++){
        //     int w= nextAns[i]-prevAns[i]-1;
        //     int h = heights[i];
        //     int area = w*h;
        //     maxans= max(maxans,area);
        // }
        for(int i=0;i<n;i++){
            int w= nextAns[i]-prevAns[i]-1;
            int h= heights[i];
            int a= w*h;
            maxans=max(maxans,a);
        }

        return maxans;
    }
};