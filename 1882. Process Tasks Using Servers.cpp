#define p pair<int,int>
#define pp tuple<long long,int,int>
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        priority_queue<p,vector<p>,greater<p>> availableServer;
        priority_queue<pp,vector<pp>,greater<pp>> busy;

        for(int i=0;i<n;i++){
            availableServer.push({servers[i],i});
        }

        vector<int>ans(m,0);
        long long time=0;
        for(int i=0;i<m;i++){
            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [freeTime, wt, serverInd] = busy.top();
                    busy.pop();

                    availableServer.push({wt, serverInd});
            }

            if(availableServer.empty()){
                time=get<0>(busy.top());
                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [freeTime, wt, serverInd] = busy.top();
                    busy.pop();

                    availableServer.push({wt, serverInd});
                }
            }

            auto [weight, index] = availableServer.top();
            availableServer.pop();

            busy.push({time+tasks[i],weight,index});

            ans[i]=index;
        }

        return ans;
    }
};