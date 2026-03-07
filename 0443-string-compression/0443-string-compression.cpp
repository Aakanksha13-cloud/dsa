class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int k=0;//to keep a track of where to modify the chars
        while(i<n){
            int j=i+1;
            // if(j<n && chars[i]!=chars[j]){
            //     chars[k]=chars[i];
            //     i++;
            //     k++;
            //     continue;
            //}
            int f=1;
            while(j<n && chars[i]==chars[j]){
                f++;
                j++;
            }
            
                chars[k]=chars[i];
                k++;
            
            if(f>1 && f<10){
                
                chars[k]=(f+'0');
                k++;
            }
            else if(f>=10){
                string freq=to_string(f);
                int l=freq.length();
               
                for(int j=0;j<l;j++){
                    
                    chars[k]=freq[j];
                    k++;
                }
            }
            
            i=i+f;
        }
        return k;
    }
};