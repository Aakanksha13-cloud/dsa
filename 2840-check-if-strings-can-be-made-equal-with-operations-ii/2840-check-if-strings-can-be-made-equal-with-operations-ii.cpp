class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2)return true;
        int n=s1.length();
        // for(int i=0;i<n;i++){
        //     int j=i+2;
        //     while(j<n){
        //         if(s1[j]==s2[i]){
        //             swap(s1[i],s1[j]);
        //         }
        //         if(s1==s2)return true;
        //         j+=2;
        //     }
        // }
        // return false;
        // unordered_map<int,set<char>> m;
        // for(int i=0;i<n;i++){
        //     char ch=s1[i];
        //     if(i%2==0)m[0].insert(ch);
        //     else m[1].insert(ch);
        // }
        // for(int i=0;i<n;i++){
        //     char ch=s2[i];
        //     if(i%2==0){
        //         if(m[0].find(ch)==m[0].end())return false;
        //     }
        //     else {
        //        if(m[1].find(ch)==m[1].end())return false; 
        //     }
        // }
        // return true;
        vector<int> even1(26, 0), odd1(26, 0);
    vector<int> even2(26, 0), odd2(26, 0);
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            even1[s1[i] - 'a']++;
            even2[s2[i] - 'a']++;
        } else {
            odd1[s1[i] - 'a']++;
            odd2[s2[i] - 'a']++;
        }
    }
    
    return (even1 == even2) && (odd1 == odd2);
    }
};