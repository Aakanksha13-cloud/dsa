class Solution {
public:
    int tribonacci(int n) {
        // vector<int> v(n+1,0);
        if(n==0)return 0;
        else if(n==1 || n==2)return 1;
    //    v[1]=1;
    //    v[2]=1;
    //    for(int i=3;i<=n;i++){
    //     v[i]=v[i-1]+v[i-2]+v[i-3];
    //    }
    //    return v[n];

    int last3 =0;
    int last2 =1;
    int last =1;
    int curr=0;
    for(int i=3;i<=n;i++){
      curr=last+last2+last3;
      last3=last2;
      last2=last;
      last=curr;
    }
    return curr;
    }
};