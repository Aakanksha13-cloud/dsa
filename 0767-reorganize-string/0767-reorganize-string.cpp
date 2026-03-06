class Solution {
public:
    string reorganizeString(string s) {
    //    int hash[26]={0};
    //    for(int i=0; i<s.size();i++){
    //     hash[s[i]-'a']++;
    //    }
    //    char maxFreqChar;
    //    int maxFreq = INT_MIN;
    //    for(int i =0;i<26;i++){
    //     if(hash[i]>maxFreq){
    //         maxFreq = hash[i];
    //         maxFreqChar = i + 'a';
    //     }
    //    }

    //    int index=0;
    //    while(maxFreq>0 && index<s.size()){
    //     s[index] = maxFreqChar;
    //     maxFreq--;
    //     index+=2;
    //    }

    //    if(maxFreq != 0)
    //     return "";

    //    hash[maxFreqChar - 'a'] =0;

    //    for(int i =0; i<26; i++){
    //     while(hash[i]>0){
    //         index= index>=s.size() ? 1 : index;
    //         s[index]= i +'a';
    //         hash[i]--;
    //         index+=2;
    //     }
    //    } 
    //    return s;
        vector<int> v(26,0);
        for(char c:s)v[c-'a']++;
        int maxf=INT_MIN;
        char maxc;
        for(int i=0;i<26;i++){
            if(v[i]>maxf){
                maxf=v[i];
                maxc= i+'a';
            }
        }
        int n=s.length();
        if(maxf>(n+1)/2)return "";
        string ans(n,' ');
        int i=0;
        while(maxf>0){
            ans[i]=maxc;
            maxf--;
            i+=2;
        }
        v[maxc-'a']=0;
        
        for(int j=0;j<26;j++){
                while(v[j]>0){
                    if(i>=n)i=1;
                    ans[i]=j+'a';
                    v[j]--;
                    i+=2;
                }
        }
        return ans;
    }

    };
