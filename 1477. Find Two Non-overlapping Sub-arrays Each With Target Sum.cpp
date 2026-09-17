//T.C=O(n)
//S.C=O(n)
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>pre(n,INT_MAX);
        int l=0;
        int best=INT_MAX;
        int curr=0;
        for(int r=0;r<n;r++){
            curr+=arr[r];
            while(curr>target){
                curr-=arr[l];
                l++;
            }
            if(curr==target){
                best=min(best,r-l+1);
            }
            pre[r]=best;
        }


        vector<int>suff(n,INT_MAX);
        int r=n-1;
        best=INT_MAX;
        curr=0;
        for(int l=n-1;l>=0;l--){
            curr+=arr[l];
            while(curr>target && l<=r){
                curr-=arr[r];
                r--;
            }
             if(curr==target){
                best=min(best,r-l+1);
            }
            suff[l]=best;
        }

        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(pre[i]!=INT_MAX && suff[i+1]!=INT_MAX)
                ans=min(ans,pre[i]+suff[i+1]);
        }
        return ans==INT_MAX?-1:ans;
    }
};