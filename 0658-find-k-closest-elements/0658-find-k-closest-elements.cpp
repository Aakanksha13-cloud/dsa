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
    
    int left = 0;
    int right = n - k;   // possible starting indices of window
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Compare distances of window edges
        if (x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    
    // Build answer directly
    vector<int> ans;
    for (int i = left; i < left + k; i++) {
        ans.push_back(arr[i]);
    }
    
    return ans;
    }
};