class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_set<char>st;
        unordered_set<char>rejected;
        int cnt=0;
        for(auto c:s){
            if(st.find(c)!=st.end()){
                st.erase(c);
            }
            else if(st.find(c)==st.end() && st.size()<n && rejected.find(c)==rejected.end()){
                st.insert(c);
            }else if(st.find(c)==st.end() && st.size()>=n && rejected.find(c)==rejected.end()){
                rejected.insert(c);
                cnt++;
            }
        }
        return cnt;
    }
};
