class Solution {
public:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        unordered_set<string>visited;
        queue<string>q;

        q.push(s);
        visited.insert(s);
        bool found=false;

        while(!q.empty()){
            string curr=q.front();
            q.pop();

            if(isValid(curr)){
                res.push_back(curr);
                found=true;
            }

            if(found){
                continue;
            }

            for(int i=0;i<curr.size();i++){
                if(curr[i]!='(' && curr[i]!=')'){
                    continue;
                }

                string nextState=curr.substr(0,i)+curr.substr(i+1);

                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
        }
        return res;
    }
};