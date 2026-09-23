class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int totalSum=0;
        for(auto it:nums){
            totalSum+=it;
        }

        long long k=totalSum-x;
        if(k<0){
            return -1;
        }
        if(k==0){
            return n;
        }
        //find the lasrgest subarray whose sum is k
        unordered_map<long long,int>mp;
        long long maxi=0;
        long long sum=0;
        
        for(int i=0;i<n;i++){
           sum+=nums[i];

           if(sum==k){
            maxi=i+1;
           }

           long long rem=sum-k;
           if(mp.find(rem)!=mp.end()){
             long long len=i-mp[rem];
             maxi=max(maxi,len);
           }

           if(mp.find(sum)==mp.end()){
            mp[sum]=i;
           }
        }
        //cout<<maxi;
        if(maxi==0){
            return -1;
        }

        return n-maxi;
    }
};