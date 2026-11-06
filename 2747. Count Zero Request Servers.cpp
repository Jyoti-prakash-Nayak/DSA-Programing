class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>>pairLogs;
        for(auto it:logs){
            pairLogs.push_back({it[1],it[0]});
        }

        sort(pairLogs.begin(),pairLogs.end());

        vector<pair<int,int>>query;
        int k=queries.size();
        for(int i=0;i<k;i++){
            query.push_back({queries[i],i});
        }

        sort(query.begin(),query.end());

       vector<int> freq(n + 1, 0);
       vector<int> ans(k, 0);
       int l=0,r=0;
       int activeServers=0;

        for(auto it:query){
            int leftLimit=it.first-x;
            int rightLimit=it.first;
            int ind=it.second;

            while(r < pairLogs.size() && pairLogs[r].first <= rightLimit) {
                int server = pairLogs[r].second;

                if(freq[server] == 0) {
                   activeServers++;
                }

                freq[server]++;
                 r++;
            }
             while(l<r  && pairLogs[l].first < leftLimit) {
                int server = pairLogs[l].second;
                
                freq[server]--;

                if(freq[server] == 0) {
                   activeServers--;
                }

                
                l++;
            }

            int cnt=n-activeServers;
            ans[ind]=cnt;
        }
        return ans;
    }
};