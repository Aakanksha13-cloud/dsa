class Solution {
public:
    //bool lastkChar(string& ans,char ch, int x){
    //     int len=(int)ans.length();
    //     for(int j=len-1;j>=len-x;j--){
    //         if(ans[j]!=ch)return false;
    //     }
    //     return true;
    // }
     string removeDuplicates(string s, int k) {
    //     string ans="";
    //     for(int i=0;i<s.length();i++){
    //         char ch=s[i];
    //         if(ans.length()<k-1)ans.push_back(ch);
    //         else{
    //             if(lastkChar(ans,ch,k-1)){
    //                 for(int j=0;j<k-1;j++)ans.pop_back();
    //             }
    //             else ans.push_back(ch);
    //         }
    //     }
    //     return ans;
       vector<pair<char,int>> count;
       for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(count.size()!=0 && count.back().first==ch)count.back().second++;
        else count.push_back({ch,1});
        if(count.back().second>=k)count.pop_back();
       }
       string ans="";
       for(auto c:count){
         int freq=c.second;
         while(freq>0){
            ans.push_back(c.first);
            freq--;
         }
       }
       return ans;
    }
};