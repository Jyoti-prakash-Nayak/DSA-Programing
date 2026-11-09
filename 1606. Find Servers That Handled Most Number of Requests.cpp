class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();

        set<int>available;
        for(int i=0;i<k;i++){
            available.insert(i);
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy;
        vector<int> count(k, 0);

        for(int i=0;i<n;i++){
            int start=i%k;
           
            while(!busy.empty() && busy.top().first<=arrival[i]){
                auto [finishTime,serverId]=busy.top();
                busy.pop();

                available.insert(serverId);
            }


            if(available.empty()) {
                continue;
            }

            // Find next available server
            auto it = available.lower_bound(start);

            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;
            
            available.erase(it);

            count[server]++;

            busy.push({arrival[i]+load[i],server});

        }

        int maxi=*max_element(count.begin(),count.end());

        vector<int>ans;
        for(int i=0;i<k;i++){
            if(count[i]==maxi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};