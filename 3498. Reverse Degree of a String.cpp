class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int ind=s[i]-'a';
            int val=26-ind;
           // cout<<val<<endl;
            sum+=(val*(i+1));
        }
        return sum;
    }
};