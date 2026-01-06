class Solution {
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node],parent);
    }

    void unionSet(int u,int v, vector<int>& parent, vector<int>& rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u!=v){
            if(rank[u]<rank[v]){
                parent[u]=v;
                rank[v]++;
            }
            else{
                parent[v]=u;
                rank[u]++;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);

        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            auto a=accounts[i];
            for(int j=1;j<a.size();j++){
                string mail= a[j];
                auto it=mp.find(mail);
                if(mp.find(mail)==mp.end())mp[mail]=i;
                else unionSet(i,it->second,parent,rank);
            }
        }

        unordered_map<int,set<string>> preAns; //set-> coz we want ans i sorted form
        for(auto it:mp){
            int accountNo= it.second;
            auto mail= it.first;
            accountNo = findParent(accountNo,parent);
            preAns[accountNo].insert(mail);
        }

        vector<vector<string>> ans;
        for(auto it:preAns){
            int accountNo=it.first;
            auto mails =it.second;
            vector<string> s;
            s.push_back(accounts[accountNo][0]);
            for(auto mail:mails)s.push_back(mail);
            ans.push_back(s);
        }
       return ans;
    }
};