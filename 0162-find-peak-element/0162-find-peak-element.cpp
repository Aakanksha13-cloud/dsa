class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(mid-1>=0 && arr[mid]>arr[mid-1] && mid+1<n && arr[mid]>arr[mid+1])return mid;
            else if(arr[mid]<arr[mid+1])s=mid+1;
            else e=mid;
        }
        return s;
    }
};