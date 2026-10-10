class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();

        long long k=1LL*k1+k2;
        int maxiDiff=0;
        long long totalDiff=0;
        vector<int>freq(100001,0);
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            freq[diff]++;
            maxiDiff=max(maxiDiff,diff);
            totalDiff=totalDiff+diff;
        }

        if(totalDiff<=k){
            return 0;
        }

        for(int d=maxiDiff;d>=0;d--){
            if(k==0){
                break;
            }
           int moves=min(k,(long long)freq[d]);
           freq[d]=freq[d]-moves;
           freq[d-1]=freq[d-1]+moves;
           k=k-moves;
        }

        long long ans=0;
        for(int d=1;d<=maxiDiff;d++){
            ans+=1LL*d*d*freq[d];
        }
        return ans;
    }
};