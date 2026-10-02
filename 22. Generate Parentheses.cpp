class Solution {
public:
    void f(string curr,int open,int close,int n,vector<string>&res){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }

        if(open<n){
            f(curr+"(",open+1,close,n,res);
        }

        if(close<open){
            f(curr+")",open,close+1,n,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        f("(",1,0,n,res);
        return res;
    }
};