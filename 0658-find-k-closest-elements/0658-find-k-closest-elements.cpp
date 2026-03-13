class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //    int n=arr.size();
       
    //    vector<int> ans;
    //    vector<pair<int,int>> v;
    //    for(int i=0;i<n;i++){
    //      int d=abs(arr[i]-x);
    //      v.push_back({d,arr[i]});
    //    } 
    //    sort(v.begin(),v.end());
    //    for(int i=0;i<k;i++){
    //     ans.push_back(v[i].second);
    //    }
    //    sort(ans.begin(),ans.end());
    //    return ans;
    int n = arr.size();
    if(k==n)return arr;
    if(k>n)return vector<int>{-1};
    
    int l=0;
    int r=n-k;//rightmost possibility of starting index of window
    int mid=r/2;
    while(l<r){
        if(x-arr[mid]>arr[mid+k]-x)l=mid+1;//compare mid of two consecutives windows
        else r=mid;
        mid=l+(r-l)/2;
    }
    return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};