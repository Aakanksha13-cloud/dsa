class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int r1=0;
        int r2=1;
        int ans=0;
        
        while(r2>r1 && r2<n && r1<n-1){
            int a=0;
            for(int i=r1;i<n;i++){    
                    string s=bank[i];
                    for(auto st:s)if(st=='1')a++;
                    if(a>0){
                        r1=i;
                        break;
                    }    
            }
            int b=0;  
            for(int i=r1+1;i<n;i++){  
                    string s=bank[i];
                    for(auto st:s)if(st=='1')b++;
                    if(b>0){
                        r2=i;
                        break;
                }    
            }

            int laser = a*b;
            ans+=laser;
            r1=r2;
            r2=r1+1;
           
        }
        return ans;
    }
};