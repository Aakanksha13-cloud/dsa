class Solution {
public:
// string ans="";
//     void backtrack(int i,int n,string &curr,unordered_set<string>& st){
//         if(i==n){
//             if(st.find(curr)==st.end()){
//                 ans=curr;
//             }
//              return;
//         }
//         if(ans!="")return;
//         curr+='0';
//         backtrack(i+1,n,curr,st);
//         curr.pop_back();

//         curr+='1';
//         backtrack(i+1,n,curr,st);
//         curr.pop_back();
//     }
    string findDifferentBinaryString(vector<string>& nums) {
        // int n= nums.size();
        // string curr="";
        // unordered_set<string> st(nums.begin(),nums.end());
        // backtrack(0,n,curr,st);
        // return ans;

        int n=nums.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(nums[i][i]=='0')ans+='1';
            else ans+='0';
        }
        return ans;
    }
};