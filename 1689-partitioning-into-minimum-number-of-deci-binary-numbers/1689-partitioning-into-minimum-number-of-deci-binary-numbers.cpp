class Solution {
public:
    int minPartitions(string n) {
        int a=0;
        for(int i=0;i<n.size();i++){
            int b= n[i]-'0';
            a=max(a,b);
        }
        return a;
    }
};