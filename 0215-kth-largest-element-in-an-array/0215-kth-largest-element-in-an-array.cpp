class Solution {
public:
    // void heapify(vector<int>& arr,int size,int currIndex){ 
    //     if(currIndex>=size-1)return;      
    //     int leftChild=2*currIndex +1;
    //     int rightChild=2*currIndex +2;
    //     int largest =currIndex;
    //     if(leftChild<size && arr[leftChild]>arr[largest])largest=leftChild;
    //     if(rightChild<size && arr[rightChild]>arr[largest])largest=rightChild;
    //     if(largest!=currIndex){
    //         swap(arr[currIndex],arr[largest]);
    //         currIndex=largest;
    //         heapify(arr,size,currIndex);
    //     }
        
    // }
    int findKthLargest(vector<int>& nums, int k) {
    //     for(int i=(nums.size()/2);i>=0;i--){
    //         heapify(nums,nums.size(),i);
    //     }
       
    //    int n = nums.size()-1;
    //    for(int i=n;i>=n-k+2;i--){
    //     swap(nums[0],nums[i]);
    //     heapify(nums,i,0);
    //    }
    //    return nums[0];

    //ny min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();

        //by max heap
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        // }
        // int i=1;
        // while(i<k){
        //     pq.pop();
        //     i++;
        // }
        // return pq.top();
    }
};