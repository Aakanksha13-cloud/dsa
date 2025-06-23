class Solution {
public:
    void heapify(vector<int>& arr,int size,int currIndex){ 
        if(currIndex>=size-1)return;      
        int leftChild=2*currIndex +1;
        int rightChild=2*currIndex +2;
        int largest =currIndex;
        if(leftChild<size && arr[leftChild]>arr[largest])largest=leftChild;
        if(rightChild<size && arr[rightChild]>arr[largest])largest=rightChild;
        if(largest!=currIndex){
            swap(arr[currIndex],arr[largest]);
            currIndex=largest;
            heapify(arr,size,currIndex);
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=(nums.size()/2);i>=0;i--){
            heapify(nums,nums.size(),i);
        }
       
       int n = nums.size()-1;
       for(int i=n;i>=n-k+2;i--){
        swap(nums[0],nums[i]);
        heapify(nums,i,0);
       }
       return nums[0];
    }
};