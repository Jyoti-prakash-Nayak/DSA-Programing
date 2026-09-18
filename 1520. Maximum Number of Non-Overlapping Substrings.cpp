// T.C=O(n)
// S.C=O(1)
class Solution {
public:
    int getRight(int L,string s,vector<int>&first,vector<int>&last){
        int R=last[s[L]-'a'];
        for(int i=L;i<=R;i++){
            int c=s[i]-'a';
            if(first[c]<L){
                return -1;
            }

            R=max(R,last[c]);
        }
        return R;
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>first(26,n);
        vector<int>last(26,-1);

        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            first[c]=min(first[c],i);
            last[c]=i;
        }

        vector<pair<int,int>>intervals;
        for(int c=0;c<26;c++){
           if(first[c]==n){
            continue;
           }

           int L=first[c];
           int R=getRight(L,s,first,last);
           if(R!=-1){
            intervals.push_back({L,R});
           }
        }

        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            if(a.second!=b.second){
                return a.second<b.second;
            }
            return a.first>b.second;
        });

        vector<string>ans;
        int lastEnd=-1;
        for(auto [L,R]:intervals){
            if(L>lastEnd){
                ans.push_back(s.substr(L,R-L+1));
                lastEnd=R;
            }
        }
       return ans;
    }
};