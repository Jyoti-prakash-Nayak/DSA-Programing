class Solution {
  public:
  vector<pair<int,int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    int n,m;
    bool check(int i,int j,int dx,int dy,vector<vector<char>>&mat,string& word){
        int l=word.size();
        
        for(int k=0;k<l;k++){
            int ni=i+k*dx;
            int nj=j+k*dy;
            
            if(ni<0 || ni>=n || nj<0 || nj>=m || mat[ni][nj]!=word[k]){
                return false;
            }
            
        }
        return true;
    }
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        n=mat.size();
        m=mat[0].size();
        
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    for(auto [dx,dy]:dirs){
                        if(check(i,j,dx,dy,mat,word)){
                            res.push_back({i,j});
                            break;
                        }
                    }
                }
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};