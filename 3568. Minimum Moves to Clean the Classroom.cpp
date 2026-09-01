//Time Complexity = O(n × m × E × 2^L)
//Space Complexity = O(n × m × E × 2^L)
class Solution {
public:
    int DR[4]={1,0,-1,0};
    int DC[4]={0,1,0,-1};
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();

        int start_r=-1,start_c=-1;
        int litter_count=0;
        map<pair<int,int>,int>litter_coord_to_idx_map;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S'){
                    start_r=i;
                    start_c=j;
                }else if(classroom[i][j]=='L'){
                    litter_coord_to_idx_map[{i,j}]=litter_count;
                    litter_count++;
                }
            }
        }


        if(litter_count==0){
            return 0;
        }

        int targetMask=(1<<litter_count)-1;//use bitmask for visited vector

        //dp vector to store min move
        vector<vector<vector<vector<int>>>> dp(
            n,vector<vector<vector<int>>>(
                m,vector<vector<int>>(
                    energy+1,vector<int>(1<<litter_count,-1)
                )
            )
        );

        queue<tuple<int,int,int,int>>q;
        q.push({start_r,start_c,energy,0});
        dp[start_r][start_c][energy][0]=0;

        while(!q.empty()){
            auto [r,c,current_e,visited_mask]=q.front();
            q.pop();

            int moves= dp[r][c][current_e][visited_mask];

            if(visited_mask==targetMask){
                return moves;
            }

            for(int k=0;k<4;k++){
                int nR=r+DR[k];
                int nC=c+DC[k];

                if(nR>=0 && nR<n && nC>=0 && nC<m && current_e>0 && classroom[nR][nC]!='X'){
                    int nextMove=moves+1;
                    int next_e=current_e-1;
                    int next_mask=visited_mask;

                    if(classroom[nR][nC]=='L'){
                      next_mask |= 1<<litter_coord_to_idx_map.at({nR,nC});
                    }else if(classroom[nR][nC]=='R'){
                        next_e=energy;
                    }

                    if(dp[nR][nC][next_e][next_mask]==-1){
                      dp[nR][nC][next_e][next_mask]=nextMove;
                      q.push({nR,nC,next_e,next_mask});
                    }
                }
            }
        }
        return -1;
    }
};