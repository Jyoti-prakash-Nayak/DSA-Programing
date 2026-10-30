//T.C = O(Ek log(Ek) + nk)
//S.C = O(n + E + nk + Ek)
#define ll long long
const ll inf=LLONG_MAX/4;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
         // Adjacency list: {adjacentNode, edgeWeight}
        // Directed graph
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adj[u].push_back({v,w});
        }

        // dist[node][count] = minimum cost to reach 'node'
        // with 'count' consecutive occurrences of its label
        vector<vector<ll>>dist(n,vector<ll>(k+1,inf));

          // Min priority queue storing {cost, node, count}
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        pq.push({0,0,1});
        dist[0][1]=0;

        while(!pq.empty()){
            auto e=pq.top();
            pq.pop();

            ll d=e[0];
            int node=e[1];
            int count=e[2];

            if(d!=dist[node][count]){
                continue;
            }

            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgWt=it.second;

                 // If labels are identical, increase count.
                // Otherwise, a new consecutive sequence starts.
                int newCount=(labels[node]==labels[adjNode]) ? count+1 : 1 ;

                if(newCount>k){
                    continue;
                }

                if(d+edgWt < dist[adjNode][newCount]){
                    dist[adjNode][newCount]=d+edgWt;
                    pq.push({dist[adjNode][newCount],adjNode,newCount});
                }
            }
        }

           // Destination may be reached with different counts.
        // Take the minimum cost among all valid states.
        ll ans=inf;
        for(int i=1;i<=k;i++){
            ans=min(ans,dist[n-1][i]);
        }

        return ans==inf?-1:ans;
    }
};